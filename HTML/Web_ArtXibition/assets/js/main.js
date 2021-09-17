const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

/* Start Count Down Timer */

var countDown = new Date("Dec 31, 2021 24:00:00").getTime();
setInterval( () => {
    var now = new Date().getTime();
    var countDownTime = countDown - now;

    if (countDownTime < 0){
        $('.days').innerHTML = 0;
    $('.hours').innerHTML = 0;
    $('.minutes').innerHTML = 0;
    $('.seconds').innerHTML = 0;
    }

    var days = Math.floor(countDownTime / (1000 * 3600 * 24));
    var hours = Math.floor((countDownTime % (1000 * 3600 * 24)) / (1000 * 60 * 60));
    var minutes = Math.floor((countDownTime % (1000 * 3600)) / (1000 * 60));
    var seconds = Math.floor((countDownTime % (1000 * 60)) / 1000);

    $('.days').innerHTML = `${days}`;
    $('.hours').innerHTML = `${hours}`;
    $('.minutes').innerHTML = `${minutes}`;
    $('.seconds').innerHTML = `${seconds}`;
},1000);

/* End Count Down Timer */

/* Start Banner */

const left = $('.banner-wapper__icon-left');
const right = $('.banner-wapper__icon-right');
const firstItem = $('.banner__link--first');

var marginLeft = 0;
var marginLeftPer = 25;

setInterval( () => {
    const widthBody = $('body').offsetWidth;

    if (widthBody >= 740 && widthBody <= 1023)
        marginLeftPer = 50;
    else if (widthBody < 739)
        marginLeftPer = 100;
    if (marginLeft === 100)
        marginLeft = 0;
    else 
        marginLeft += marginLeftPer;
    firstItem.style.marginLeft = -1*marginLeft + '%';
}, 3000);

left.onclick = () => {
    const widthBody = $('body').offsetWidth;

    if (widthBody >= 740 && widthBody <= 1023)
        marginLeftPer = 50;
    else if (widthBody < 739)
        marginLeftPer = 100;
    if ($('body').right)
        if (marginLeft === 0)
            marginLeft = 100;
        else 
            marginLeft -= marginLeftPer;
    firstItem.style.marginLeft = -1*marginLeft + '%';
};

right.onclick = () => {
    const widthBody = $('body').offsetWidth;

    if (widthBody >= 740 && widthBody <= 1023)
        marginLeftPer = 50;
    else if (widthBody < 739)
        marginLeftPer = 100;
    if (marginLeft === 100)
        marginLeft = 0;
    else 
        marginLeft += marginLeftPer;
    firstItem.style.marginLeft = -1*marginLeft + '%';
};

/* End Banner */


/* Start Menu Mobile */

const menu = $('.navbar-mobile');

menu.onclick = () => {
    if (menu.classList.contains('active'))
        menu.classList.remove('active');
    else
    menu.classList.add('active');
};

/* End Menu Mobile */