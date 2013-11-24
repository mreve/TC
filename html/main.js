var username;
var rightTabsOpened = 2;
var accounts = ["anna.dymek.75@facebook.com", "mreve@users.v-lo.krakow.pl", "z1088891@student.tcs.uj.edu.pl"];
var enabled = [true, false, true];

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
                        if (is_account_active(i))
                            input += '<img class="icon" src="img/icon-active.png"/>';
                        else
                            input += '<img class="icon" src="img/icon-inactive.png"/>';
                    input += '</td>';
                    input += '<td>';
                        input += accounts[i];
                    input += '</td>';
                    input += '<td>';
                        if (is_account_enabled(i))
                            input += '<input type="checkbox" onclick="checkbox_state_changed(id);" class="account-checkbox" id="ae-' + i + '"/>ON';
                        else
                            input += '<input type="checkbox" onclick="checkbox_state_changed(id);" class="account-checkbox" id="ae-' + i + '"/>OFF';
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
                    var i = accounts.length-1;
                    var input = '<tr>';
                        input += '<td><img class="icon" src="img/icon-inactive.png"/></td>';
                        input += '<td>' + accounts[i] + '</td>';
                        input += '<td><input type="checkbox" onclick="checkbox_state_changed(id);" class="account-checkbox" id="ae-' + i + '"/>OFF</td>';
                    input += '</tr>';
                    $("#home-accounts").append(input);
                    $("#ae-" + i).attr("checked", is_account_enabled(i));
                }
            });

            $(".account-checkbox").click(function() {
                var len = $(this).id;
                var id = parseInt(len.slice(3, len.length-1));
                enabled[id] = !enabled[id];
            });

        });
    } else if (id.indexOf("contacts") != -1) {
        $("#tab-contacts").toggleClass("tab-upper-active", true);

        $("#partial").load("partials/contacts.html", function() {

            /*	Here there would come all the jQuery selectors for tab CONTACTS	*/
            $("#tab-contacts-icon").attr("src", "img/icon-tab-contacts-dark.png");

            $("#add-accounts").click(function() {
                disable_tabs();
                able_tab("tab-home");
                return false;
            });
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
    username = TChat.getUser();

    able_tab("tab-contacts");

    $("#main-space").css("min-height", (rightTabsOpened+1) * 55);

    $(".tab-description").click(function() {
        disable_tabs();
        able_tab($(this).attr("id"));
    });
});
