function Show({title, message, duration, time}) {
    const main = document.getElementById('toast');
    const delay = (time / 1000).toFixed(2);

    main.style.transition = `NotiShow .3s ease, NotiHidden 1s ease ${delay}s forwards`;
    
    if (main){
        const toast = document.createElement('div');
        const icons = {
            success: 'fas fa-check-circle',
            info: 'fas fa-info-circle',
            warn: 'fas fa-exclamation-circle'
        };

        toast.classList.add('toast', `toast--${duration}`);
        
        toast.innerHTML = `
            <div class="toast__icon"><i class="${icons[duration]}"></i></div>
            <div class="toast__noti">
                <h3>${title}</h3>
                <p>${message}</p>
            </div>
            <div class="toast__close"><i class="fas fa-times"></i></div>
        `;
        
        main.appendChild(toast);
        
        const checkClose = setTimeout(function() {
            main.removeChild(toast);
        },time + 1000);

        toast.onclick = function(e) {
            if (e.target.closest('.toast__close')){
                main.removeChild(toast);
                clearTimeout(checkClose);
            }
        }
    }
}

function ShowSuccess () {
    Show({
        title: 'Success',
        message: 'Thực hiện thành công.',
        duration: 'success',
        time: 3000
    });
}

function ShowInfo () {
    Show({
        title: 'Info',
        message: 'Thực hiện thành công.',
        duration: 'info',
        time: 3000
    });
}

function ShowWarn () {
    Show({
        title: 'Warning',
        message: 'Thực hiện thành công.',
        duration: 'warn',
        time: 3000
    });
}