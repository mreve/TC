function add_message(message) {
    console.log("add_message called with message: ",message);
    if (message  !== "") {
       $('#messages').prepend('<div class="message">'+message+'</div>');
    }
}

$(document).ready(function() {
    $("#send_btn").click(function() {
        XmppTest.sendMessage($("#input_message").val());
    });

    $("#log_btn").click(function() {
        XmppTest.login($("#username").val(), $("#password").val(), $("#friend").val());
    });
});
