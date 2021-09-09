function ShowToast ({title, message, type, time}){
    const main = document.getElementById('toast');

    if (main) {
        const toast = document.createElement('div');
        toast.classList.add('toast',`toast--${type}`);

        const delay = (time / 1000).toFixed(2);
        const Icons = {
            success: 'fas fa-check-circle',
            info: 'fas fa-info-circle',
            warning: 'fas fa-exclamation-circle'
        };

        toast.style.animation = `NotiIn .3s ease, NotiOut ease 1s ${delay}s forwards`;
        toast.innerHTML = `
            <div class="toast__icon"><i class="${Icons[type]}"></i></div>
            <div class="toast__noti">
                <h2>${title}</h2>
                <p>${message}</p>
            </div>
            <div class="toast__close"><i class="fas fa-times"></i></div>
        `;
        main.appendChild(toast);

        const AutoClose = setTimeout(function() {
            main.removeChild(toast);
        }, time+1000);

        toast.onclick = function(e) {
            if (e.target.closest('.toast__close')){
                main.removeChild(toast);
                clearTimeout(AutoClose);
            }
        };
    }
}



function ShowSuc() {
    ShowToast({
        title: 'Success!',
        message: 'Thực hiện thành công.',
        type: 'success',
        time: 3000
    });
}

function ShowInfo() {
    ShowToast({
        title: 'Info!',
        message: 'Thực hiện thành công.',
        type: 'info',
        time: 3000
    });
}

function ShowWarn() {
    ShowToast({
        title: 'Warning!',
        message: 'Thực hiện thành công.',
        type: 'warning',
        time: 3000
    });
}

