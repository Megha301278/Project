function validateLoginForm() {
  var password = document.getElementById("logPassword").value;
  var email = document.getElementById("logEmail").value;

  if (password == "" || email == "") {
    document.getElementById("errorMsg").innerHTML = "Please fill the required fields"
    return false;
  }

  else if (password.length < 8) {
    document.getElementById("errorMsg").innerHTML = "Your password must include atleast 8 characters"
    return false;
  }
  else {
    alert("Successfully logged in");
    return true;
  }
}

function validateSignupform() {
          var email = document.getElementById("signEmail").value;
          var password = document.getElementById("signPassword").value;
          var password1 = document.getElementById("signPassword1").value;

          if (email == "" || password == "" || password1 == "") {
            document.getElementById("errorMsg").innerHTML = "Please fill the required fields"
            return false;
          }

          else if(password==password1)
            document.getElementBy("errorMsg").innerHTML="Password does not match."
            return false;

          else if (password.length < 8) {
            document.getElementById("errorMsg").innerHTML = "Your password must include atleast 8 characters"
            return false;
          }
          else {
            alert("Successfully signed up");
            return true;
          }
        }
