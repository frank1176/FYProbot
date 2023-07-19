import { Component,OnInit,ElementRef } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { StreamingService } from '../services/streaming.service';
@Component({
  selector: 'app-live',
  templateUrl: './live.component.html',
  styleUrls: ['./live.component.css']
})
export class LiveComponent {
  
  mac_address : string = ""
  username: string = ""
  localVideo: any;
  remoteVideo: any; 
  
  constructor (
    private route: ActivatedRoute, 
    // private romoService:RomoService,
    private elementRef: ElementRef,
    private streamingService: StreamingService,
    ){}

  ngOnInit(): void {
    
    this.route.paramMap.subscribe(param => {
      console.log("----------------");
      console.log(param);
      console.log("----------------");
      
      this.mac_address = param.get('mac_address')!.toString()
      this.username = param.get('user')!.toString()
    
      console.log(this.mac_address);
      
    })
    this.goin()
    // this.getUserName()
    // this.sendDeviceReadyMQTT()
    
   
  }
  goin(){
    this.localVideo = this.elementRef.nativeElement.querySelector('#localVideo')
    this.remoteVideo = this.elementRef.nativeElement.querySelector('#remoteVideo')
    this.streamingService.connectWebSocket(this.username, this.mac_address,this.localVideo, this.remoteVideo, "romo")
  }
  // getUserName(){
  //   this.romoService.getRomoUser('romo_user_detail', this.mac_address).subscribe({
  //     next : (response:any) => {
  //       console.log(response)
  //       this.username = response.body["username"]

  //       this.localVideo = this.elementRef.nativeElement.querySelector('#localVideo')
  //       this.remoteVideo = this.elementRef.nativeElement.querySelector('#remoteVideo')
  //       this.livestreaming.connectWebSocket(this.username, this.mac_address,this.localVideo, this.remoteVideo, "romo")
  //     }
  //   })
  // }

  // sendDeviceReadyMQTT(){
  //   let pubtopic = "device_connect_status"

  //   setInterval(()=> {
  //     // Get current date and time (timestamp)
  //     let timestamp: number = Date.now();
      
  //     const message = {
  //       "datetime": timestamp, 
  //       "mac_address": this.mac_address
  //     }
  //     this.eventMqtt.publish(pubtopic, JSON.stringify(message)).subscribe()

  //   }, 5000)

  // }
}
