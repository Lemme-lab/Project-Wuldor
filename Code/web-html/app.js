function changemode(evt, cityName) {
  var i, tabcontent, tablinks;

  tabcontent = document.getElementsByClassName("tabcontent");
  for (i = 0; i < tabcontent.length; i++) {
    tabcontent[i].style.display = "none";
  }

  tablinks = document.getElementsByClassName("tablinks");
  for (i = 0; i < tablinks.length; i++) {
    tablinks[i].className = tablinks[i].className.replace(" active", "");
  }

  document.getElementById(cityName).style.display = "block";
  evt.currentTarget.className += " active";
}

var power_img_power = document.querySelector('.power_img_power');
var power_img_status = document.querySelector('.power_img_status');
var check_img = document.querySelector('.check_img');
var images1 = ['PowerOn.png', 'PowerOff.png'];
var images2 = ['connection_off.png', 'connection_on.png'];
var images3 = ['check_green.png', 'check_red.png'];
var i = 0;

var input1 = 0;
var input2 = 0;
var input3 = 0;
var input4 = 0;
var input5 = 0;
var input6 = 0;

var slider1 = document.getElementById("myRange1");
var output1 = document.getElementById("inaxis1");
output1.placeholder = "              AXIS 1";
slider1.oninput = function () {
  output1.placeholder = this.value;
  input1 = this.value;
}
var slider2 = document.getElementById("myRange2");
var output2 = document.getElementById("inaxis2");
output2.placeholder = "              AXIS 2";
slider2.oninput = function () {
  output2.placeholder = this.value;
  input2 = this.value;
}
var slider3 = document.getElementById("myRange3");
var output3 = document.getElementById("inaxis3");
output3.placeholder = "              AXIS 3";
slider3.oninput = function () {
  output3.placeholder = this.value;
  input3 = this.value;
}
var slider4 = document.getElementById("myRange4");
var output4 = document.getElementById("inaxis4");
output4.placeholder = "              AXIS 4";
slider4.oninput = function () {
  output4.placeholder = this.value;
  input4 = this.value;
}
var slider5 = document.getElementById("myRange5");
var output5 = document.getElementById("inaxis5");
output5.placeholder = "              AXIS 5";
slider5.oninput = function () {
  output5.placeholder = this.value;
  input5 = this.value;
}
var slider6 = document.getElementById("myRange6");
var output6 = document.getElementById("inaxis6");
output6.placeholder = "              AXIS 6";
slider6.oninput = function () {
  output6.placeholder = this.value;
  input6 = this.value;
}

function next_power() {
  if (i >= images1.length - 1) i = -1;
  i++;
  return setImg1();
}

function next_connection() {
  if (i >= images2.length - 1) i = -1;
  i++;
  return setImg2();
}

function next_check() {
  if (i >= images3.length - 1) i = -1;
  i++;
  return setImg3();
}


function setImg1() {
  return power_img_power.setAttribute('src', "data/" + images1[i]);
}

function setImg2() {
  return power_img_status.setAttribute('src', "data/" + images2[i]);
}

function setImg3() {
  return check_img.setAttribute('src', "data/" + images3[i]);
}


number = 0;
var loader_img = ["loading_gif.gif", "loading_png.png"];


function character() {
  image = document.getElementById('hiddenimageid');
  image.src = "data/" + loader_img[number];
  if (number == 1) {
    number = 0;
  } else {
    number++;
  }

}

var counter = 0;



function addCoordiantes() {
  counter++;
  var eoat = document.querySelector("#input4").value;
  var text_in = input1 + "/" + input2 + "/" + input3 + "/" + input4 + "/" + input5 + "/" + input6 + "/" + eoat;
  var tag = document.createElement("H1");
  tag.id = "element" + counter;
  tag.className = "style_element";
  var text = document.createTextNode(text_in);
  tag.appendChild(text);
  var element = document.getElementById("jselements");
  element.appendChild(tag);
  console.log(counter);
}

function removeCoordinates() {
  var child = document.getElementById("element" + counter);
  counter--;
  child.parentNode.removeChild(child);
}


/*
  const words = input.split(" ");
  if(words[0] == "Coordinates:"){
  document.getElementById("coordinates_text").innerHTML = words[1];
}*/