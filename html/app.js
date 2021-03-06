
function toggle_visibility(id) {
    var e = document.getElementById(id);
    if(e.style.display == 'block')
        e.style.display = 'none';
    else
        e.style.display = 'block';
}

//var users = [{ un:'mreve', pwd:''}, { un:'kotek', pwd:'kotek'}, { un:'dawid', pwd:'kochany'}];

function user_in_base(usrn, pswd) {
    for (var i = 0; i<users.length; i++)
        if (users[i].un == usrn && users[i].pwd == pswd)
            return true;
    return false;
}

function username_taken(usrn) {
    for (var i = 0; i<users.length; i++)
        if (users[i].un == usrn)
            return true;
    return false;
}

function fill_alert(msg, fieldGroupName, omitUn) {
    $("#form-alert").html(msg);
    if (!omitUn)
        $("#" + fieldGroupName + "-username").val("");
    $("#" + fieldGroupName + "-password").val("");
    if (fieldGroupName == "register")
        $("#" + fieldGroupName + "-repeat").val("");
}

$(document).ready(function() {
    $("#sign-in-submit").click(function() {
        if (!UserStore.login($("#sign-in-username").val(), $("#sign-in-password").val())) {
            fill_alert("Wrong username or password", "sign-in", false);
        } else {
            fill_alert("Great", "sign-in", false);
            TChat.loadMain(window.screen.width-400, 20, 400, 700);
            /*
            newWindow.addEventListener(Ti.CLOSED, function() {
                Ti.API.set('logged_user', {username: null, password: null});
                welcomeWindow.show();
                fill_alert("Logged out succesfully");
            });*/
        }
        return false;
    });
    $("#register-submit").click(function() {
        if ($("#register-password").val() != $("#register-repeat").val()) {
            fill_alert("Incorrect password", "register", true);
        } else if (!UserStore.registerUser($("#register-username").val(), $("#register-password").val())) {
            fill_alert("Username already taken", "register", false);
        } else {
            fill_alert("Registration completed", "register", false);
            toggle_visibility("register-form");
        }
        return false;
    });

    $("#toggler-header").click(function() {
        toggle_visibility("register-form");
    });
});
