const userMenu = document.querySelector('.user-item--menu')
const userMenuIO = document.querySelector('.user-item__menu')
const main = document.querySelector('.main')
const navTimes = document.querySelectorAll('.nav-time')
const navTimeBig = document.querySelector('.nav-time-big')
const placeItems = document.querySelectorAll('.place-item')
const changeNumber = document.querySelectorAll('#number-people')
const addNumber = document.querySelectorAll('.add-number')
const subNumber = document.querySelectorAll('.sub-number')
const navSearchItems = document.querySelectorAll('.nav-time-item')
const nhanPhongs = document.querySelectorAll('.mount-date.mount-date--num > li')
const mainClick2 = document.querySelectorAll('.nav-time-item-click-2')

var check = true;
var i = 0;

/* Menu User */

userMenuIO.style.display = "none"

userMenuIO.addEventListener('click', function(event) {
    event.stopImmediatePropagation();
})

userMenu.addEventListener('click',function(event){
    if (userMenuIO.style.display == "none")
        userMenuIO.style.display = "block"
    else
        userMenuIO.style.display = "none"
    event.stopImmediatePropagation();
})

main.addEventListener('click', function(){
    if (userMenuIO.style.display == "block")
        userMenuIO.style.display = "none"
})


//Back To Top

window.addEventListener('scroll',function() {

    if (window.pageYOffset > 58){

        setTimeout(function(){
            navTimeBig.style.display = "none";
        },100)
        this.document.querySelector('.navbar-conteiner').classList.add('navbar-conteiner--scroll')
        this.document.querySelector('.navbar__place').classList.add('navbar__place--scroll')

        this.document.querySelector('.navbar__place--no-flexed').classList.add('navbar__place--no-flexed--scroll')
    }
    else{
        setTimeout(function(){
            navTimeBig.style.display = "flex";
        },100)
        this.document.querySelector('.navbar-conteiner').classList.remove('navbar-conteiner--scroll')
        this.document.querySelector('.navbar__place').classList.remove('navbar__place--scroll')

        this.document.querySelector('.navbar__place--no-flexed').classList.remove('navbar__place--no-flexed--scroll')

    }
})

document.querySelector('.navbar__place--flexed').addEventListener('click', function(event) {
    document.querySelector('.navbar__place').classList.remove('navbar__place--scroll')
    navTimeBig.style.display = "flex"
    navSearchItems[0].classList.add('nav-time-item--click')
    navSearchItems[4].classList.add('nav-time-item--click')
    event.stopImmediatePropagation()
})


// Change Search Big

for (const placeItem of placeItems){
    i++;
    if (i <= placeItems.length - 1) {
        placeItem.addEventListener('click',function() {
            if (placeItem.classList.contains('place-item--active') == false){
                placeItem.classList.add('place-item--active')
                if (check == true){
                    navTimeBig.classList.add('nav-time-big--scroll')
                    check = false;
                }
                else {
                    navTimeBig.classList.remove('nav-time-big--scroll')
                    check = true;
                }
            }
            for (const placeItem2 of placeItems)
                if (placeItem2.classList.contains('place-item--active') == true && placeItem != placeItem2)
                    placeItem2.classList.remove('place-item--active')
        })
    }
    else if (i == placeItems.length - 1)
        i = 0;
}


// Click search big

for (const navSearchItem of navSearchItems)
    navSearchItem.addEventListener('click',function(event){
        if (navSearchItem.classList.contains('nav-time-item--click') == false){
            for (const navSearchItem2 of navSearchItems)
                if (navSearchItem2.classList.contains('nav-time-item--click'))
                    navSearchItem2.classList.remove('nav-time-item--click');

            if (navTimeBig.classList.contains('nav-time-big--click') == false)
                navTimeBig.classList.add('nav-time-big--click');
            navSearchItem.classList.add('nav-time-item--click');
        }
        else navSearchItem.classList.remove('nav-time-item--click');
        event.stopImmediatePropagation();
    })


// Địa điểm

document.querySelector('.nav-time-item-click-1').addEventListener('click',function(event) {
    event.stopImmediatePropagation();
})

document.querySelector('.mount-date-item').addEventListener('click',function(event) {
    document.querySelector('.mount-date-item').classList.add('mount-date--click');
    event.stopImmediatePropagation();
})

// Nhận phòng

for (const nhanPhong of nhanPhongs)
    nhanPhong.addEventListener('click',function(event) {
    if (!nhanPhong.classList.contains('mount-date--disable')) {

        for (const nhanPhong2 of nhanPhongs)
            if (nhanPhong2.classList.contains('mount-date--click'))
                nhanPhong2.classList.remove('mount-date--click');

        nhanPhong.classList.add('mount-date--click');
        event.stopImmediatePropagation();
    }
})

main.addEventListener('click',function(){
    for (const navSearchItem2 of navSearchItems)
        if (navSearchItem2.classList.contains('nav-time-item--click'))
            navSearchItem2.classList.remove('nav-time-item--click');
    navTimeBig.classList.remove('nav-time-big--click');
})

for (const mainClick of mainClick2)
    mainClick.addEventListener('click',function(event) {
        event.stopImmediatePropagation();
})

// Khách

document.querySelector('.nav-time-item-click-3').addEventListener('click', function(evt){
    evt.stopImmediatePropagation();
})

// Change People

for (let num = 0; num < changeNumber.length; num++){
    if (Number(changeNumber[num].value) > Number(0)){
        if (subNumber[num].classList.contains('sub-number--disable'))
            subNumber[num].classList.remove('sub-number--disable')
    }
    else {
        if (!subNumber[num].classList.contains('sub-number--disable'))
            subNumber[num].classList.add('sub-number--disable')
    }

    addNumber[num].addEventListener('click',function(){
        changeNumber[num].value = Number(changeNumber[num].value) + Number(1);
        if (subNumber[num].classList.contains('sub-number--disable'))
            subNumber[num].classList.remove('sub-number--disable')
    })

    subNumber[num].addEventListener('click',function(){
        if (Number(changeNumber[num].value) > Number(0))
            changeNumber[num].value = Number(changeNumber[num].value) - Number(1);
        if (Number(changeNumber[num].value) <= Number(0))
            if (!subNumber[num].classList.contains('sub-number--disable'))
                subNumber[num].classList.add('sub-number--disable')
    })    
}   

// Navbar Search Mobile
const searchMobile = document.querySelector('.navbar--mobile');
const searchMenuMobile = document.querySelector('.navbar-search--mobile')

searchMobile.addEventListener('click', (event) => {
    searchMenuMobile.style.display = 'block';
});