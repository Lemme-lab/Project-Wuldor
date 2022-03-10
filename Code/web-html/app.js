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
  
  function next_power(){
      if(i >= images1.length-1) i = -1;
      i++;
      return setImg1();			 
  }
  
  function next_connection(){
    if(i >= images2.length-1) i = -1;
    i++;
    return setImg2();			 
  }

  function next_check(){
    if(i >= images3.length-1) i = -1;
    i++;
    return setImg3();			 
  }


function setImg1(){
  return power_img_power.setAttribute('src', "data/"+images1[i]);    
}

  function setImg2(){
      return power_img_status.setAttribute('src', "data/"+images2[i]);    
  }

  function setImg3(){
    return check_img.setAttribute('src', "data/"+images3[i]);    
  }


  number = 0;
  var loader_img = ["loading_gif.gif","loading_png.png"
];


function character() {
  image = document.getElementById('hiddenimageid');
  image.src = "data/" + loader_img[number];
  if(number==1){
    number = 0;
  }else{
    number++;
  }
  
}

var counter = 2;


function addCoordiantes(){
   var text_in = "312/23/123/212/78/54";
   var tag = document.createElement("h1");
   tag.id = "style_element";
   tag.className = "element" + counter;
   var text = document.createTextNode(text_in);
   tag.appendChild(text);
   var element = document.getElementById("elements");
   element.appendChild(tag);
   console.log("WOrked");
   alert("WOrked");
   counter++;
   console.log("counter");
}
    

/*
  const words = input.split(" ");
  if(words[0] == "Coordinates:"){
  document.getElementById("coordinates_text").innerHTML = words[1];
}*/