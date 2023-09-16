//=====================
//HTML code for webpage
//=====================
const char webpageCont[] PROGMEM = 
R"=====(
<!-- AIzaSyBokl70BKubVLLhS-UWSSIqLuKyl78DvIg -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />

    <link
      rel="stylesheet"
      href="https://unpkg.com/leaflet@1.9.2/dist/leaflet.css"
      integrity="sha256-sA+zWATbFveLLNqWO2gtiw3HL/lh1giY/Inf1BJ0z14="
      crossorigin=""
    />
    <!-- Make sure you put this AFTER Leaflet's CSS -->
    <script
      src="https://unpkg.com/leaflet@1.9.2/dist/leaflet.js"
      integrity="sha256-o9N1jGDZrf5tS+Ft4gbIK7mYMipq9lqpVJ91xHSyKhg="
      crossorigin=""
    ></script>
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
      crossorigin="anonymous"
    ></script>
    <link
      href="https://fonts.googleapis.com/css2?family=Prompt&display=swap"
      rel="stylesheet"
    />
    <link
      rel="icon"
      type="image/x-icon"
      href="data:image/jpeg;base64,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"
    />

    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <!-- <link rel="stylesheet" href="./css/bootstrap.min.css"> -->
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC"
      crossorigin="anonymous"
    />
    <title>Dashboard</title>
  </head>
  <!-- 🟢 -->
  <body style="font-family: 'Prompt', sans-serif">
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
      <div class="container-fluid" style="justify-content: center">
        <a class="navbar-brand" style="display: flex">
          <!-- <img
            width="60"
            height="50"
            class="d-inline-block align-text-top"
            style="border-radius: 5px"
            src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/11/Move_Forward_Party_Logo.svg/1200px-Move_Forward_Party_Logo.svg.png"
          /> -->
          <h5 style="margin: 10px" id="SEC">00:00.00 SEC</h5>
        </a>
        <button
          class="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="#navbarNavAltMarkup"
          aria-controls="navbarNavAltMarkup"
          aria-expanded="false"
          aria-label="Toggle navigation"
        >
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
          <div class="navbar-nav">
            <a class="nav-link disabled" href="#"
              >สงวนลิขสิทธิ์ ทีม Absolute Ace</a
            >
            <a
              class="nav-link active"
              aria-current="page"
              href="#"
              id="deployrocket"
              >🔴 Deploy Rocket</a
            >
            <a class="nav-link active" href="#" id="deployparachute"
              >🔴 Deploy Rocket Parachute</a
            >
            <a class="nav-link active" href="#" id="deploycansatparachute"
              >🔴 Deploy Cansat Parachute</a
            >
            <a
              class="nav-link active"
              href="#"
              tabindex="-1"
              aria-disabled="true"
              id="land"
              >🔴 Land</a
            >
          </div>
        </div>
      </div>
    </nav>

    <div class="container-fluid" style="margin-top: 10px; margin-bottom: 50px">
      <div
        class="row row-cols-1 row-cols-md-2 row-cols-md-3"
        style="justify-content: center"
      >
        <div class="col-md-5">
          <div id="map" style="height: 500px"></div>
        </div>
        <div class="col-12 col-md-4">
          <div class="row">
            <div class="col">
              <table class="table table-bordered">
                <thead class="table-dark" style="border: none">
                  <tr>
                    <th>MPU6050</th>
                  </tr>
                </thead>
                <tr>
                  <th>axis-X</th>
                  <td id="GYROaxisx">0</td>
                </tr>
                <tr>
                  <th>axis-Y</th>
                  <td id="GYROaxisy">0</td>
                </tr>
                <tr>
                  <th>accelerate-Y</th>
                  <td id="GYROaccy">0</td>
                </tr>
                <tr>
                  <th>accelerate-X</th>
                  <td id="GYROaccx">0</td>
                </tr>
              </table>
            </div>
            <div class="col">
              <table class="table table-bordered">
                <thead class="table-dark" style="border: none">
                  <tr>
                    <th>BME280</th>
                  </tr>
                </thead>
                <tr>
                  <th>Temp (C)</th>
                  <td id="BMEtemp">0</td>
                </tr>
                <tr>
                  <th>Altitude (m.)</th>
                  <td id="BMEaltitude">0</td>
                </tr>
                <tr>
                  <th>Pressure</th>
                  <td id="BMEpressure">0</td>
                </tr>
                <tr>
                  <th>Humidity</th>
                  <td id="BMEhumidity">0</td>
                </tr>
              </table>
            </div>

            <div class="col">
              <table class="table table-bordered">
                <thead class="table-dark" style="border: none">
                  <tr>
                    <th>GPS</th>
                  </tr>
                </thead>
                <tr>
                  <th>latitude</th>
                  <td id="GPSlat">0</td>
                </tr>
                <tr>
                  <th>longitude</th>
                  <td id="GPSlong">0</td>
                </tr>
              </table>
            </div>
          </div>
          <div class="row">
            <div class="col">
              <button
                type="button"
                class="btn btn-primary"
                onclick="downloadlog(GYROlog,'GYRO')"
              >
                Download mpu6050 log
              </button>
            </div>
            <div class="col">
              <button
                type="button"
                class="btn btn-primary"
                onclick="downloadlog(BMElog,'BME')"
              >
                Download bme280 log
              </button>
            </div>
            <div class="col">
              <button
                type="button"
                class="btn btn-primary"
                onclick="downloadlog(GPSlog,'GPS')"
              >
                Download gps log
              </button>
            </div>
          </div>

          <div class="row" style="margin: 15px">
            <div class="ratio ratio-4x3">
              <div>
                <h1>input</h1>
                <div style="display: flex">
                  <input
                    class="form-control form-control-md"
                    id="formFileLg"
                    accept="video/*"
                    type="file"
                  />
                  <button type="button" class="btn btn-dark" id="upload_btn">
                    Process
                  </button>
                </div>
                <div class="imgcontroller" style="margin:5px; display:flex; justify-content:space-evenly;">
                  <div class="btn btn-secondary" id="back">←</div>

                  <div class="btn btn-secondary" id="next">→</div>
                    <input type="text" id="typeText" class="form-control" placeholder="index" itemid="index" value="0">
                    <div class="btn btn-dark" id="select">select</div>
               

                </div>
                <div class="list_img">
                  <div >
                    <h1>Original</h1>
                  <img style="width: 100%;"id="originalimg" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/de/Aspect-ratio-4x3.svg/2560px-Aspect-ratio-4x3.svg.png" alt="">
  </div>
    
                  <div >
                    <h1>save Image</h1>
                    <img style="width: 100%;" id="save_image" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/de/Aspect-ratio-4x3.svg/2560px-Aspect-ratio-4x3.svg.png" alt="">
  
                  </div>
                  <div> <h1>unsupervised</h1>
                  <img style="width: 100%;" id="unsupervised" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/de/Aspect-ratio-4x3.svg/2560px-Aspect-ratio-4x3.svg.png" alt="">
         </div>
         <div id="Chart"> <h1>Chart</h1>
          <img style="width: 100%;" id="chart" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/de/Aspect-ratio-4x3.svg/2560px-Aspect-ratio-4x3.svg.png" alt="">
  </div>
  <div id="info">
    <p>blank</p>
  </div>
                </div>

                      </div>
            </div>
          </div>
        </div>
      </div>
    </div>

    <script>



      const deployrocket_status = 0;
      var i = 0;
      var x = 0;
      const deploycansatparachute_status = 0;
      const deployrocketparachute_status = 0;
      const land_status = 0;
      const input = document.getElementById("formFileLg");
      const video = document.getElementById("video-tag");
      const videoSource = document.createElement("source");
      var BMEtemp = document.getElementById("BMEtemp");
      var BMEhumidity = document.getElementById("BMEhumidity");
      var BMEaltitude = document.getElementById("BMEaltitude");
      var BMEpressure = document.getElementById("BMEpressure");
      var chart = document.getElementById("chart");
      var unsupervised = document.getElementById("unsupervised");
      var save_image = document.getElementById("save_image");
      var original = document.getElementById("original");
      var info = document.getElementById("info");
      var next = document.getElementById("next");
      var back = document.getElementById("back");
      var select = document.getElementById("select");
      var index = document.getElementById("index");






      var GYROaxisx = document.getElementById("GYROaxisx");
      var GYROaxisy = document.getElementById("GYROaxisy");
      var GYROaccx = document.getElementById("GYROaccx");
      var GYROaccy = document.getElementById("GYROaccy");

      var GPSlat = document.getElementById("GPSlat");
      var GPSlong = document.getElementById("GPSlong");

      var SEC = document.getElementById("SEC");

      //<!-- uploadvideo -->

      document
        .getElementById("upload_btn")
        .addEventListener("click", function () {
          const files = input.files || [];
          if (!files.length) return;
          const reader = new FileReader();
          reader.onload = function (e) {
            videoSource.setAttribute("src", e.target.result);
            video.appendChild(videoSource);
            video.load();
          };
          reader.onprogress = function (e) {
            console.log("progress: ", Math.round((e.loaded * 100) / e.total));
          };
          reader.readAsDataURL(files[0]);
        });

      //uploadtowebserver

      var latandlng = [];

      // Initializes map
      // Sets initial coordinates and zoom level

      // Sets map data source and associates with map
      var marker, zoomed, pathLine;

      function updatedata() {
        latandlng.push([JSONobj.LAT, JSONobj.LONG]);

        var Lan = latandlng[latandlng.length - 1][0];
        var Long = latandlng[latandlng.length - 1][1];
        marker = L.marker([Lan, Long]).addTo(map);
        pathLine = L.polyline(latandlng).addTo(map);
        if (latandlng.length > 1) {
          map.panTo([Lan, Long]);
        }
      }

      var map;
      var i = 0;

      function setupmap() {
        map = L.map("map", {
          center: [JSONobj.LAT, JSONobj.LONG],
          zoom: 18,
        });
        L.tileLayer("http://{s}.google.com/vt/lyrs=s&x={x}&y={y}&z={z}", {
          maxZoom: 22,
          attribution: "Absolute Ace",
          subdomains: ["mt0", "mt1", "mt2", "mt3"],
        }).addTo(map);
      }
      InitWebSocket();

      function InitWebSocket() {
        var websock = new WebSocket(
          "ws://" + window.location.hostname + ":81/"
        );

        websock.onclose = function (e) {
          console.log(
            "Socket is closed. Reconnect will be attempted in 1 second.",
            e.reason
          );
          //setTimeout(function() {
          InitWebSocket();
          //  }, 500);
        };
        websock.onerror = function (err) {
          console.error(
            "Socket encountered error: ",
            err.message,
            "Closing socket"
          );
          websock.close();
        };

        websock.onmessage = function (evt) {
          JSONobj = JSON.parse(evt.data);
          if (i < 1) {
            setupmap();
            i++;
          }
          BMEtemp.innerHTML = JSONobj.TEMP;
          BMEhumidity.innerHTML = JSONobj.HUM;
          BMEpressure.innerHTML = JSONobj.PRES;
          BMEaltitude.innerHTML = JSONobj.ALT;
          SEC.innerHTML = JSONobj.SEC + "SEC";
          //var s = JSONobj.SEC;
          GYROaxisx.innerHTML = JSONobj.AXISX;
          GYROaxisy.innerHTML = JSONobj.AXISY;
          GYROaccx.innerHTML = JSONobj.ACCX;
          GYROaccy.innerHTML = JSONobj.ACCY;

          GPSlat.innerHTML = JSONobj.LAT;
          GPSlong.innerHTML = JSONobj.LONG;

          BMElog.push([
            JSONobj.SEC,
            [JSONobj.TEMP, JSONobj.HUM, JSONobj.PRES, JSONobj.ALT],
          ]);
          GPSlog.push([
            JSONobj.SEC,
            [JSONobj.AXISX, JSONobj.AXISY, JSONobj.ACCX, JSONobj.ACCY],
          ]);
          GYROlog.push([JSONobj.SEC, [JSONobj.LAT, JSONobj.LONG]]);
          updatedata();
        };
      }

      // map

      // status bar function

      //download
      var BMElog = [];
      var GPSlog = [];
      var GYROlog = [];

      function download(filename, text) {
        var element = document.createElement("a");
        element.setAttribute(
          "href",
          "data:text/plain;charset=utf-8," + encodeURIComponent(text)
        );
        element.setAttribute("download", filename);

        element.style.display = "none";
        document.body.appendChild(element);

        element.click();

        document.body.removeChild(element);
      }

      function downloadlog(hardware, name) {
        download(name + "_log.txt", JSON.stringify(hardware));
      }

//original

let SHEET_ID = '1nPFZn9Foltouenq9psJxgCqAykgRqWk0T_33wC-qeOI'
let SHEET_TITLE = 'name';
let SHEET_RANGE = 'A2:B16'
var original_lst = [];
let ORIGINAL_URL = ('https://docs.google.com/spreadsheets/d/' + SHEET_ID + '/gviz/tq?sheet=' + SHEET_TITLE + '&range=' + SHEET_RANGE);
let SAVEIMG_URL = ('https://docs.google.com/spreadsheets/d/' + "1b5ff6722jBEeKowAL6dvAo5KnKh-0bemEnDk9kO4Wos" + '/gviz/tq?sheet=' + SHEET_TITLE + '&range=' + SHEET_RANGE);
let UNSUPERVISED_URL = ('https://docs.google.com/spreadsheets/d/' + "1YOfYrG2R7nMyan4AQCTv3sMxocK4bDg-BjXkbdo7lE0" + '/gviz/tq?sheet=' + SHEET_TITLE + '&range=' + SHEET_RANGE);
let CHART_URL = ('https://docs.google.com/spreadsheets/d/' + "1ULnwkhYOFstUcr0ZXfxhzLPeqWOi44gPAsSZ58d-VQ0" + '/gviz/tq?sheet=' + SHEET_TITLE + '&range=' + SHEET_RANGE);
let TEXT_URL = ('https://docs.google.com/spreadsheets/d/' + "1qx_x7ZZ4p_5wx1Ta2hewHd2-aIeoIw61LQ0otIHhZnE" + '/gviz/tq?sheet=' + SHEET_TITLE + '&range=' + SHEET_RANGE);

document.getElementById("select").addEventListener("click", function(){
fetch(ORIGINAL_URL)
.then(res => res.text())
.then(rep => {
    var data = JSON.parse(rep.substr(47).slice(0,-2));
    
    
    let i = parseInt(document.getElementById("typeText").value);
    console.log(i);
    let name = data.table.rows[i].c[0].v;
    let id = data.table.rows[i].c[1].v;
    
    document.getElementById("originalimg").src = "https://drive.google.com/uc?export=view&id="+id;


  

    
})
fetch(UNSUPERVISED_URL)
.then(res => res.text())
.then(rep => {
    var data = JSON.parse(rep.substr(47).slice(0,-2));
    
    
    let i = parseInt(document.getElementById("typeText").value);
    console.log(i);
    let name = data.table.rows[i].c[0].v;
    let id = data.table.rows[i].c[1].v;
    
    document.getElementById("unsupervised").src = "https://drive.google.com/uc?export=view&id="+id;
})
fetch(SAVEIMG_URL)
.then(res => res.text())
.then(rep => {
    var data = JSON.parse(rep.substr(47).slice(0,-2));
    
    
    let i = parseInt(document.getElementById("typeText").value);
    console.log(i);
    let name = data.table.rows[i].c[0].v;
    let id = data.table.rows[i].c[1].v;
    
    document.getElementById("save_image").src = "https://drive.google.com/uc?export=view&id="+id;

})
fetch(TEXT_URL)
.then(res => res.text())
.then(rep => {
    var data = JSON.parse(rep.substr(47).slice(0,-2));
    
    
    let i = parseInt(document.getElementById("typeText").value);
    console.log(i);
    let name = data.table.rows[i].c[0].v;
    let id = data.table.rows[i].c[1].v;
    
    document.getElementById("info").innerHTML = id;

})
fetch(CHART_URL).then(res => res.text()).then(rep => {
    var data = JSON.parse(rep.substr(47).slice(0,-2));
    
    
    let i = parseInt(document.getElementById("typeText").value);
    console.log(i);
    let name = data.table.rows[i].c[0].v;
    let id = data.table.rows[i].c[1].v;
    
    document.getElementById("chart").src = "https://drive.google.com/uc?export=view&id="+id;
})})






document.getElementById("next").addEventListener("click",function(){
    fetch(ORIGINAL_URL)
.then(res => res.text())
.then(rep => {
    var data = JSON.parse(rep.substr(47).slice(0,-2));
    
    
    let i = parseInt(document.getElementById("typeText").value);
    i++;
    console.log(i);
    let name = data.table.rows[i].c[0].v;
    let id = data.table.rows[i].c[1].v;
    
    document.getElementById("originalimg").src = "https://drive.google.com/uc?export=view&id="+id;
    

})



})
document.getElementById("next").addEventListener("click",function(){

  document.getElementById("typeText").value =    parseInt(document.getElementById("typeText").value)+1;

})
document.getElementById("back").addEventListener("click",function(){

  document.getElementById("typeText").value =    parseInt(document.getElementById("typeText").value)-1;

})
    </script>
  </body>
</html>


)=====";