const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

const taps = $$('.tap-item');
const panes = $$('.tap-pane-item');
const line = $('.line');

line.style.width = $('.tap-item.active').offsetWidth + 'px';
line.style.left = $('.tap-item.active').offsetLeft + 'px';

taps.forEach((tap, index) => {

    tap.onclick = function() {
        $('.tap-item.active').classList.remove('active');
        $('.tap-pane-item.active').classList.remove('active');
        
        this.classList.add('active');
        panes[index].classList.add('active');

        line.style.width = this.offsetWidth + 'px';
        line.style.left = this.offsetLeft + 'px';
    };
});