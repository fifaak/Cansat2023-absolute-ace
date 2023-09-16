//=====================
//HTML code for webpage
//=====================
const char webpageCont[] PROGMEM = 
R"=====(
<!DOCTYPE HTML>
<html>
    <title>ESP32 WebSocket Server</title>
    <link rel="stylesheet" href="ESP32_WS_BME280.css">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Caveat:wght@700&family=Kalam:wght@700&family=Shadows+Into+Light+Two&display=swap" rel="stylesheet">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Baloo+Tamma+2:wght@600&family=Caveat:wght@700&family=Kalam:wght@700&family=Shadows+Into+Light+Two&display=swap" rel="stylesheet">
<!----------------------C S S------------------------>
<style>
      body
      {
        font-family: 'Baloo Tamma 2', cursive;
        background-color: rgba(0, 0, 0, 0.116);
      }
      h1
      {
        font-family: 'Shadows Into Light Two', cursive;
        color: crimson;
        font-size: 50px;
        margin-left: 20px;
      }
      h2
      {
        color: darkblue;
      }
      .title1
      {
        margin-left: 150px;
      }
      .BME
      {
        font-family: 'Baloo Tamma 2', cursive;
        background-color: gold;
        width: 110px;
        font-size: 20px;
        border: 2px solid black;
        margin-left: 150px;
      }
      .BMEo
      {
        font-family: 'Baloo Tamma 2', cursive;
        color:blue;
        background-color:blanchedalmond;
        width: 80px;
        font-size: 20px;
        text-align: center;
        border: 2px solid black;
      }
      .BMEo:hover
      {
        background-color: rgba(5, 0, 0, 0.144);
        transition: 0.5s;
      }
      .unt1
      {
        font-family: 'Baloo Tamma 2', cursive;
        color:blue;
      }
      .title2
     {
       margin-left: 150px;
     }
     .analog
     {
      font-family: 'Baloo Tamma 2', cursive;
      background-color: gold;
      width: 110px;
      font-size: 20px;
      border: 2px solid black;
      margin-bottom: 5px;
      margin-left: 150px;
     }
     .analogo
     {
      font-family: 'Baloo Tamma 2', cursive;
      color:blue;
      background-color:blanchedalmond;
      width: 80px;
      font-size: 20px;
      text-align: center;
      border: 2px solid black;
     }
     .analogo:hover
     {
      background-color: rgba(5, 0, 0, 0.144);
      transition: 0.5s;
     }
     .unt2
      {
        font-family: 'Baloo Tamma 2', cursive;
        color:blue;
      }
</style>
<!----------------------H T M L------------------------>
</head>
<body>
    <h1>ESP32 WebSocket Server</h1>
    <h2>
        <p>
            <span class="title1">BME280 Measurements</span><br>
            <select class="BME" id="BMEtype">
                <option value="temp">Temp</option>
                <option value="hum">Humidity</option>
                <option value="pres">Pressure</option>
            </select>
            <input class="BMEo" id="BMEop">
            <span class="unt1" id="unit1"></span>
        </p>
        <p>
            <span class="title2">ESP32 Analog Inputs</span><br>
            <select class="analog" id="analogType">
                <option value="ldr">LDR</option>
                <option value="pot">POT</option>
            </select>
            <input class="analogo" id="analogop">
            <span class="unt2" id="unit2"></span>
        </p>
    </h2>    
</body>
<!----------------------JavaScript------------------------>
<script>
  InitWebSocket()
  function InitWebSocket()
  {
    websock = new WebSocket('ws://'+window.location.hostname+':81/');
    websock.onmessage=function(evt)
    {
       JSONobj = JSON.parse(evt.data);
       
       var BME = document.getElementById("BMEtype").value;
       var BMEval, BMEunit;
       if(BME == "temp")
       {
          BMEval = JSONobj.TEMP; BMEunit = " C";   
       }
       if(BME == "hum")
       {
          BMEval = JSONobj.HUM; BMEunit = " %";
       }
       if(BME == "pres")
       {
          BMEval = JSONobj.PRES; BMEunit = " hPa";
       }
       document.getElementById("BMEop").value = BMEval;
       document.getElementById("unit1").innerHTML = BMEunit;

       var analogTyp = document.getElementById("analogType").value;
       var analogip, ESPunit;
       if(analogTyp == "ldr")
       {
         analogip = JSONobj.LDR; ESPunit = " (0 --> 4095)";
       }
       if(analogTyp == "pot")
       {
         analogip = JSONobj.POT; ESPunit = " Volts";
       }
       document.getElementById("analogop").value = analogip;
       document.getElementById("unit2").innerHTML = ESPunit;
    }
  }
</script>
</html>
)=====";