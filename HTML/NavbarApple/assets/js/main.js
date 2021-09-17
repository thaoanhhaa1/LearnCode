const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

const searchNavbar = $('.navbar__item--search');

searchNavbar.onclick = () => {
    $('.navbar').toggleClass('navbar--hidden');
};