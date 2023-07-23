import { Injectable } from '@angular/core';
import { environment } from 'src/environments/environment.development';
import {HttpClient,HttpHeaders} from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class ObjectDectectionService {
  pc:any
  sender:any
  remoteStream:any
  localStream:any
  remoteobjectvideo:any
  videoType: string = "";
  constructor(private http:HttpClient) { }

  createPeerConnection(){
    this.pc = new RTCPeerConnection(environment.pcConfig)

    this.pc.addEventListener('track',(event:any)=>{
      if(event.track.kind === 'video'){
         this.remoteStream=event.streams[0]

      }
    })

    return this.pc
  }

  negotiate(){
    return this.pc.createOffer().then((offer:any)=>{
      this.pc.setLocalDescription(offer)
      return this.pc
    }).then(()=>{
      return new Promise((resolve:any)=>{
        if(this.pc.iceConnectionState === 'complete'){
          resolve()
        }else{
          const checkState =()=>{
            if(this.pc.iceGatheringState === 'complete' ){
              this.pc.removeEventListener('icegatheringstatechange',checkState)
              resolve()
            }
          }
          this.pc.addEventListener('icegatheringstatechange',checkState)
        }
      })
    }).then(()=>{
      var offer =this.pc.localDescription
      
      let data=JSON.stringify({
        sdp:offer.sdp,
        type:offer.type,
        video_transform:this.videoType,
      })
      return this.http.post(environment.object.host+environment.object.live_path,data).subscribe({
        next:(ans:any)=>{
          return this.pc.setremotedescription(ans)

        },
        error:(err:any)=>{
          alert(err)
        }
      })

    })
  }

  // start(remoteLocalVideo:any, remoteFaceVideo:any, videoType:string, userName:string, mac_address?:string){
    
  //   this.createPeerConnection()
  //   var constraints={
  //     audio:false,
  //     video:true
  //   }  

  //   if(constraints.audio || constraints.video){
  //     if(this.videoType === 'object_dectection'){
  //       this.localStream = this.localStream.captureStream()
  //       this.localStream.getTracks().forEach((track:any)=>{
  //         this.sender =this.pc.addTrack(track,this.localStream)
  //         return this.negotiate()
  //       })
  //     }else{
  //       navigator.mediaDevices.getUserMedia(constraints).then((stream:any)=>{
  //         this.localStream = stream
  //         this.localStream.getTracks().forEach((track:any)=>{
  //           this.sender =this.pc.addTrack(track,this.localStream)
  //         })
  //         return this.negotiate()
  //       })
  //     }
  //   }else{
  //       this.negotiate()
  //   }
  // }

  
  stop(){
    this.pc.remoteStream(this.localStream)
    this.pc.removeTrack(this.sender)
    this.pc.close()
    
  }
}
