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
  var images1 = ['PowerOn.png', 'PowerOff.png'];
  var images2 = ['connection_off.png', 'connection_on.png'];
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


function setImg1(){
  return power_img_power.setAttribute('src', "data/"+images1[i]);    
}

  function setImg2(){
      return power_img_status.setAttribute('src', "data/"+images2[i]);    
  }


/*
  const words = input.split(" ");
  if(words[0] == "Coordinates:"){
  document.getElementById("coordinates_text").innerHTML = words[1];
}*/