################
# aiortc (python)
sudo su -
apt -y install python3 python3-pip libgl1
exit
cd ~
git clone git@github.com:aiortc/aiortc.git

pip install opencv-python aiohttp aiortc
cd aiortc/examples/server/
python server.py
################




################
# node
sudo su -
curl -fsSL https://deb.nodesource.com/setup_18.x | bash -
apt -y install gcc g++ make build-essential
curl -sL https://dl.yarnpkg.com/debian/pubkey.gpg | gpg --dearmor | tee /usr/share/keyrings/yarnkey.gpg >/dev/null
echo "deb [signed-by=/usr/share/keyrings/yarnkey.gpg] https://dl.yarnpkg.com/debian stable main" | tee /etc/apt/sources.list.d/yarn.list
apt -y update
apt -y dist-upgrade
apt -y install nodejs yarn
node --version
npm --version

npm install -g npm@latest
npm --version

################


################
# headless web browser
sudo su -
apt-get -y install unzip
wget https://chromedriver.storage.googleapis.com/109.0.5414.74/chromedriver_linux64.zip
unzip chromedriver_linux64.zip
mv chromedriver /usr/bin/chromedriver
chown root:root /usr/bin/chromedriver
chmod +x /usr/bin/chromedriver
rm -rf chromedriver_linux64.zip

apt-get -y install chromium-browser
apt-get -y install chromium-codecs-ffmpeg
apt-get -y install npm
# npm install puppeteer-core@v1.11.0
cd /home/engineer/FYProbot/chromium-browser
npm install puppeteer-core@v19.7.5
npm i puppeteer

######################### testing#######
cat > /home/engineer/FYProbot/chromium-browser/index.js << EOF
    const puppeteer = require('puppeteer-core');

    //function delay(time) {
    //   return new Promise(function(resolve) { 
    //        setTimeout(resolve, time)
    //    });
    //}

    (async () => {
        const browser = await puppeteer.launch({executablePath: '/usr/bin/chromium-browser', 
            args: ['--use-fake-ui-for-media-stream'], dumpio: true}); // dumpio get all console log 

        const page = await browser.newPage();
        //const mac_address = process.argv[2]
        //const url = 'https://romo.kynoci.com:4200/login_romo/' + mac_address
        const url = 'https://google.com/' 
        await page.goto(url);

        // await page.waitForSelector('input[name=userNameInput]');
        // await page.\$eval('input[name=userNameInput]', el => el.value = '00:B0:D0:63:C2:26');
        // const loingBtn = await page.\$('#loginButton');
        // loingBtn.click();
        // await delay(5000);

        // const answerBtn = await page.\$('#answerButton');
        // answerBtn.click();
        // await delay(5000);

        await page.screenshot({path: 'screeshot12.png'});
        // await browser.close();
    })();
EOF
cat /home/engineer/FYProbot/chromium-browser/index.js
ls
node /home/engineer/FYProbot/chromium-browser/index.js e4:5f:01:42:52:3e
node /home/engineer/FYProbot/chromium-browser/index.js
# testing#######################

#################cham########################
cat > /home/engineer/FYProbot/chromium-browser/index.js << EOF
    const puppeteer = require('puppeteer-core');

    function delay(time) {
        return new Promise(function(resolve) { 
            setTimeout(resolve, time)
        });
    }

    (async () => {
        const browser = await puppeteer.launch({executablePath: '/usr/bin/chromium-browser', 
            ignoreDefaultArgs: ['--mute-audio'],
            args: ['--use-fake-ui-for-media-stream', '--autoplay-policy=no-user-gesture-required', '--alsa-output-device=plug:hw']});
        const page = await browser.newPage();
        await page.goto('https://www.youtube.com/watch?v=o0j8UAKOPpY?autoplay=1');
        await page.screenshot({path: 'screeshot1.png'});
        await delay(5000);

        await page.screenshot({path: 'screeshot2.png'});
        // await browser.close();
    })();
EOF
#################cham########################

################ working ver1########################
cat > /home/engineer/FYProbot/chromium-browser/index.js << EOF
    const puppeteer = require('puppeteer-core');

    // function delay(time) {
    //     return new Promise(function(resolve) { 
    //         setTimeout(resolve, time)
    //     });
    // }

    (async () => {
        const browser = await puppeteer.launch({executablePath: '/usr/bin/chromium-browser', 
            // args: ['--use-fake-ui-for-media-stream'], dumpio: true}); // dumpio get all console log 
            args: ['--no-sandbox', '--disable-setuid-sandbox','--use-fake-ui-for-media-stream']});
        const page = await browser.newPage();
        const mac_address = process.argv[2]
        const url = 'https://romo.kynoci.com:4200/login_romo/' + mac_address
        // const url = 'https://google.com/'
        await page.goto(url);

        // await page.waitForSelector('input[name=userNameInput]');
        // await page.$eval('input[name=userNameInput]', el => el.value = '00:B0:D0:63:C2:26');
        // const loingBtn = await page.$('#loginButton');
        // loingBtn.click();
        // await delay(5000);

        // const answerBtn = await page.$('#answerButton');
        // answerBtn.click();
        // await delay(5000);

        await page.screenshot({path: 'screeshot12.png'});
        // await browser.close();
    })();
EOF
################

################
# UV4L 
# https://www.highvoltagecode.com/post/webrtc-on-raspberry-pi-live-hd-video-and-audio-streaming(fail)
sudo su -
curl https://www.linux-projects.org/listing/uv4l_repo/lpkey.asc | sudo apt-key add -
echo "deb https://www.linux-projects.org/listing/uv4l_repo/raspbian/stretch stretch main" | sudo tee /etc/apt/sources.list.d/uv4l.list
apt-get update && apt-get upgrade
apt-get install uv4l-webrtc
apt-get install uv4l-webrtc-armv6
uv4l --external-driver --device-name=video0

#  http://yourraspberrypiip:8080/stream/webrtc


################