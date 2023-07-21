    const puppeteer = require('puppeteer-core');

    function delay(time) {
        return new Promise(function(resolve) { 
            setTimeout(resolve, time)
        });
    }

    (async () => {
        const browser = await puppeteer.launch({executablePath: '/usr/bin/chromium-browser', 
            // args: ['--use-fake-ui-for-media-stream'], dumpio: true}); // dumpio get all console log 
            // args: ['--no-sandbox', '--disable-setuid-sandbox']});
            args: ['--no-sandbox', '--disable-setuid-sandbox','--use-fake-ui-for-media-stream']});
            // args: ['--no-sandbox', '--disable-setuid-sandbox','--use-fake-ui-for-media-stream', '--use-fake-device-for-media-stream']});
        const page = await browser.newPage();
        // const mac_address = process.argv[2]
        // const url = 'https://romo.kynoci.com:4200/login_romo/' + mac_address
        // const url = 'https://google.com/'
        const url = 'https://robot.kynoci.com:4200/login_romo/lim/cham' 
        await page.goto(url);

        // await page.waitForSelector('input[name=userNameInput]');
        // await page.$eval('input[name=userNameInput]', el => el.value = '00:B0:D0:63:C2:26');
        // const loingBtn = await page.$('#loginButton');
        // loingBtn.click();
        // await delay(5000);

        // const answerBtn = await page.$('#answerButton');
        // answerBtn.click();
        // await delay(5000);
        await delay(5000)
        await page.screenshot({path: 'screeshot3.png'});
        // await browser.close();
    })();
