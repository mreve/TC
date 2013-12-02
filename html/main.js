var username;
var rightTabsOpened = 2;
var accounts = ["anna@kitten.com", "me@krakow.pl", "asdf@student.asdf.pl"];
var enabled = [true, false, true];
var contacts = [["dawid", "meg", "kaicik"], [], []];

function toggle_visibility(id) {
    var e = document.getElementById(id);
    if(e.style.display == 'block')
        e.style.display = 'none';
    else
        e.style.display = 'block';
}

function disable_tabs() {
    $("#tab-home").toggleClass("tab-upper-active", false);
    $("#tab-home-icon").attr("src", "img/icon-tab-home-light.png");
    
    $("#tab-contacts").toggleClass("tab-upper-active", false);
    $("#tab-contacts-icon").attr("src", "img/icon-tab-contacts-light.png");

    for (var i = 0; i < rightTabsOpened; i++)
        $("#tab-conv-" + i).toggleClass("tab-right-active", false);
}

function is_account_enabled(account) {
    return enabled[account];
}

// TODO: check if account is active
function is_account_active(account) {
    return Math.random() >= 0.5;
}

// TODO: that probably should save it in the database
function checkbox_state_changed(id) {
    var my_id = parseInt(id.substring(3, id.length-1));
    enabled[id] = !enabled[id];
}

function able_tab(id) {

    if (id.indexOf("home") != -1) {
        $("#tab-home").toggleClass("tab-upper-active", true);


        $("#partial").load("partials/home.html", function() {


            /*	Here there would come all the jQuery selectors for tab HOME	*/
            $("#home-hello").html("<h2>Hello " + username + "!</h2>");
            $("#tab-home-icon").attr("src", "img/icon-tab-home-dark.png");

            for (var i = 0; i < accounts.length; i++) {               
                var input = '<tr>';
                    input += '<td>';
                        if (accounts[i].length > 30)
                            input += accounts[i].substring(0, 27) + '...';
                        else
                            input += accounts[i];
                    input += '</td>';
                    input += '<td>';
                        if (is_account_enabled(i)) {
                            input += '<input type="checkbox" class="account-checkbox" id="ae-' + i + '"/></td>';
                            input += '<td id="ae-desc-' + i + '">' + 'ON' + '</td>';
                        }
                        else {
                            input += '<input type="checkbox" class="account-checkbox" id="ae-' + i + '"/></td>';
                            input += '<td id="ae-desc-' + i + '">' + 'OFF' + '</td>';
                        }
                    input += '<td id="ae-icon-' + i + '">';
                        if (is_account_enabled(i)) {
                            if (is_account_active(i))
                                input += '<img class="icon" src="img/icon-active.png"/>';
                            else
                                input += '<img class="icon" src="img/icon-inactive.png"/>';
                        } else {
                            input += '<img class="icon" src="img/icon-empty.png"/>';
                        }
                    input += '</td>';
                input += '</tr>';
                $("#home-accounts").append(input);
                $("#ae-" + i).attr("checked", is_account_enabled(i));
            }

            $("#add-account").click(function() {
                var new_account = prompt("Please enter account address:");
                if (new_account) {
                    accounts.push(new_account);
                    enabled.push(false);
                    contacts.push([]);
                    var i = accounts.length-1;
                    var input = '<tr>';
                        input += '<td>';
                            if (accounts[i].length > 25)
                                input += accounts[i].substring(0, 22) + '...';
                            else
                                input += accounts[i];
                        input += '</td>';
                        input += '<td><input type="checkbox" class="account-checkbox" id="ae-' + i + '"/></td>';
                        input += '<td id="ae-desc-' + i + '">' + 'OFF' + '</td>';
                        input += '<td id="ae-icon-' + i + '"><img class="icon" src="img/icon-empty.png"/></td>';
                    input += '</tr>';
                    $("#home-accounts").append(input);
                    $("#ae-" + i).attr("checked", is_account_enabled(i));
                }
                $("#tab-home").click();
            });

            $(".account-checkbox").click(function() {
                var len = $(this).attr("id");
                var id = parseInt(len.substring(3, len.length));
                enabled[id] = !enabled[id]; // TODO: this will be different probably
                if (is_account_enabled(id)) {
                    $("#ae-desc-" + id).html("ON");
                    // TODO: try to connect here!
                    if (is_account_active(id))
                        $("#ae-icon-" + id).html('<img class="icon" src="img/icon-active.png"/>');
                    else
                        $("#ae-icon-" + id).html('<img class="icon" src="img/icon-inactive.png"/>');
                }
                else {
                    $("#ae-desc-" + id).html("OFF");
                    $("#ae-icon-" + id).html('<img class="icon" src="img/icon-empty.png"/>');
                }
            });  

        });
    } else if (id.indexOf("contacts") != -1) {
        $("#tab-contacts").toggleClass("tab-upper-active", true);

        $("#partial").load("partials/contacts.html", function() {

            /*	Here there would come all the jQuery selectors for tab CONTACTS	*/
            $("#tab-contacts-icon").attr("src", "img/icon-tab-contacts-dark.png");

            var any_active_accounts = false;
            for (var i = 0; i < accounts.length; i++)
                if (is_account_active(i)) {
                    any_active_accounts = true;
                    break;
                }
            if (any_active_accounts) {
                $("#no-active-accounts").css("display", "none");
                $("#some-active-accounts").css("display", "block");

                for (var i = 0; i < accounts.length; i++) {
                    var frame = '<fieldset id="account-contacts-' + i + '">';
                        frame += '<legend>';
                            if (accounts[i].length > 25)
                                frame += accounts[i].substring(0, 22) + '...';
                            else
                                frame += accounts[i];
                        frame += '</legend>';
                        frame += '<table id="ac-' + i + '" style="width: ' + (document.width-150) + 'px;"><tbody>';
                        frame += '<tr><td style="float: right; width: 100%;"></td></tr>';
                        for (var j = 0; j < contacts[i].length; j++) {
                            frame += '<tr>';
                                frame += '<td>' + contacts[i][j] + '</td>';
                            frame += '</tr>';
                        }
                        frame += '</tbody></table>';
                    frame += '</fieldset>';
                    $("#list-of-accounts").append(frame);
                    var visibility = '';
                        if (is_account_enabled(i))
                            visibility = "block";
                        else
                            visibility = "none";
                    $("#account-contacts-" + i).css("display", visibility);
                }



            } else {
                $("#no-active-accounts").css("display", "block");
                $("#some-active-accounts").css("display", "none");

                $("#add-accounts").click(function() {
                    disable_tabs();
                    able_tab("tab-home");
                    return false;
                });
            }
        });
    } else {
        $("#" + id).toggleClass("tab-right-active", true);
        $("#partial").load("partials/conv.html", function() {
            /*	And here there would come all the jQuery selectors for tab CONVERSATION	*/
        });
    }

    if (id.indexOf("home") != -1 || id.indexOf("contacts") != -1)
        $("#" + id).toggleClass("tab-upper-active", true);
    else
        $("#" + id).toggleClass("tab-right-active", true);
}

$(document).ready(function() {
    username = UserStore.getUsername();


    able_tab("tab-contacts");

    $("#main-space").css("min-height", (rightTabsOpened+1) * 55);

    $(".tab-description").click(function() {
        disable_tabs();
        able_tab($(this).attr("id"));
    });
});
