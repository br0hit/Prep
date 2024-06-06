<!DOCTYPE html>
<html><script>
    window[Symbol.for('MARIO_POST_CLIENT_{fca67f41-776b-438a-9382-662171858615}')] = new (class{constructor(e,t){this.name=e,this.destination=t,this.serverListeners={},this.bgRequestsListeners={},this.bgEventsListeners={},window.addEventListener("message",(e=>{const t=e.data,s=!(t.destination&&t.destination===this.name),n=!t.event;if(!s&&!n)if("MARIO_POST_SERVER__BG_RESPONSE"===t.event){const e=t.args;if(this.hasBgRequestListener(e.requestId)){try{this.bgRequestsListeners[e.requestId](e.response)}catch(e){}delete this.bgRequestsListeners[e.requestId]}}else if("MARIO_POST_SERVER__BG_EVENT"===t.event){const e=t.args;if(this.hasBgEventListener(e.event))try{this.bgEventsListeners[t.id](e.payload)}catch(e){}}else if(this.hasServerListener(t.event))try{this.serverListeners[t.event](t.args)}catch(e){}}))}emitToServer(e,t){const s=this.generateUIID(),n={args:t,destination:this.destination,event:e,id:s};return window.postMessage(n,location.origin),s}emitToBg(e,t){const s=this.generateUIID(),n={bgEventName:e,requestId:s,args:t};return this.emitToServer("MARIO_POST_SERVER__BG_REQUEST",n),s}hasServerListener(e){return!!this.serverListeners[e]}hasBgRequestListener(e){return!!this.bgRequestsListeners[e]}hasBgEventListener(e){return!!this.bgEventsListeners[e]}fromServerEvent(e,t){this.serverListeners[e]=t}fromBgEvent(e,t){this.bgEventsListeners[e]=t}fromBgResponse(e,t){this.bgRequestsListeners[e]=t}generateUIID(){return"xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx".replace(/[xy]/g,(function(e){const t=16*Math.random()|0;return("x"===e?t:3&t|8).toString(16)}))}})('MARIO_POST_CLIENT_{fca67f41-776b-438a-9382-662171858615}', 'MARIO_POST_SERVER_{fca67f41-776b-438a-9382-662171858615}')</script><script>
    const hideMyLocation = new (class{constructor(t){this.clientKey=t,this.watchIDs={},this.client=window[Symbol.for(t)];const e=navigator.geolocation.getCurrentPosition,o=navigator.geolocation.watchPosition,n=navigator.geolocation.clearWatch,i=this;navigator.geolocation.getCurrentPosition=function(t,o,n){i.handle(e,"GET",t,o,n)},navigator.geolocation.watchPosition=function(t,e,n){return i.handle(o,"WATCH",t,e,n)},navigator.geolocation.clearWatch=function(t){if(-1===t)return;const e=i.watchIDs[t];return delete i.watchIDs[t],n.apply(this,[e])}}handle(t,e,o,n,i){const a=this.client.emitToBg("HIDE_MY_LOCATION__GET_LOCATION");let r=this.getRandomInt(0,1e5);if(this.client.fromBgResponse(a,(a=>{if(a.enabled)if("SUCCESS"===a.status){const t=this.map(a);o(t)}else{const t=this.errorObj();n(t),r=-1}else{const a=[o,n,i],c=t.apply(navigator.geolocation,a);"WATCH"===e&&(this.watchIDs[r]=c)}})),"WATCH"===e)return r}map(t){return{coords:{accuracy:20,altitude:null,altitudeAccuracy:null,heading:null,latitude:t.latitude,longitude:t.longitude,speed:null},timestamp:Date.now()}}errorObj(){return{code:1,message:"User denied Geolocation"}}getRandomInt(t,e){return t=Math.ceil(t),e=Math.floor(e),Math.floor(Math.random()*(e-t+1))+t}})('MARIO_POST_CLIENT_{fca67f41-776b-438a-9382-662171858615}')
  </script><head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <link rel="stylesheet alternate" type="text/css" href="josephusproblem1_files/cses.css" id="styles">
  <link rel="stylesheet " type="text/css" href="josephusproblem1_files/cses-dark.css" id="styles-dark">
  <meta name="theme-color" content="#292929" id="theme-color">
  <script type="application/json" id="darkmode-enabled">true</script>
  <script src="josephusproblem1_files/ui.js"></script><script ecommerce-type="extend-native-history-api">(()=>{const e=history.pushState,t=history.replaceState,a=history.back,r=history.forward;function n(){window.postMessage({_custom_type_:"CUSTOM_ON_URL_CHANGED"})}history.pushState=function(){e.apply(history,arguments),n()},history.replaceState=function(){t.apply(history,arguments),n()},history.back=function(){a.apply(history,arguments),n()},history.forward=function(){r.apply(history,arguments),n()}})()</script>
  <link rel="stylesheet" type="text/css" href="josephusproblem1_files/all.min.css">
<link rel="stylesheet" type="text/css" href="josephusproblem1_files/prettify.css"></head>
<body class="with-sidebar vsc-initialized">
  <div class="header">
    <div>
      <a href="https://cses.fi/" class="logo"><img src="josephusproblem1_files/logo.png" alt="CSES"></a>
      <a class="menu-toggle" onclick="document.body.classList.toggle('menu-open');">
        <i class="fas fa-bars"></i>
      </a>
      <div class="controls">
                <a class="account" href="https://cses.fi/user/211854">br0hit</a>
        <span>—</span>
                        <a href="https://cses.fi/darkmode" title="Toggle dark mode" onclick="return toggle_theme()"><i aria-label="Dark mode" class="fas fa-adjust"></i><span>Dark mode</span></a>
                <a href="https://cses.fi/logout" title="Log out"><i aria-label="Log out" class="fas fa-sign-out-alt"></i><span>Log out</span></a>
              </div>
    </div>
  </div>
  <div class="skeleton">

  <div class="navigation">
    <div class="title-block">
      <h3><a href="https://cses.fi/problemset/list/">CSES Problem Set</a></h3>
      <h1>Josephus Problem I</h1>
<ul class="nav">
<li><a href="https://cses.fi/problemset/task/2162/" class="current">Task</a></li>
<li><a href="https://cses.fi/problemset/submit/2162/">Submit</a></li>
<li><a href="https://cses.fi/problemset/view/2162/">Results</a></li>
<li><a href="https://cses.fi/problemset/stats/2162/">Statistics</a></li>
<li><a href="https://cses.fi/problemset/tests/2162/">Tests</a></li>
</ul>
    </div>
    <div class="sidebar"></div>
  </div>

  <div class="content-wrapper">

    <div class="content">


<title>CSES - Josephus Problem I</title><link rel="stylesheet" href="josephusproblem1_files/katex.min.css">
<script defer="defer" src="josephusproblem1_files/katex.min.js"></script>
<script defer="defer" src="josephusproblem1_files/copy-tex.min.js"></script>

<script>
addEventListener("DOMContentLoaded", function (e) {
    const mathElements = document.getElementsByClassName("math");
    const macros = {};
    for (let element of mathElements) {
        katex.render(element.textContent, element, {
            displayMode: element.classList.contains("display"),
            throwOnError: false,
            globalGroup: true,
            macros,
        });
    }
});
</script>
<ul class="task-constraints">
<li><b>Time limit:</b> 1.00 s</li>
<li><b>Memory limit:</b> 512 MB</li>
</ul>
<input type="hidden" name="course" value="problemset">
<input type="hidden" name="task" value="2162">
<div class="md"><p>Consider a game where there are <span class="math inline"><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">n</span></span></span></span></span> children (numbered <span class="math inline"><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><mo separator="true">,</mo><mn>2</mn><mo separator="true">,</mo><mo>…</mo><mo separator="true">,</mo><mi>n</mi></mrow><annotation encoding="application/x-tex">1,2,\dots,n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.8389em; vertical-align: -0.1944em;"></span><span class="mord">1</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord">2</span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="minner">…</span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mpunct">,</span><span class="mspace" style="margin-right: 0.1667em;"></span><span class="mord mathnormal">n</span></span></span></span></span>)
 in a circle. During the game, every other child is removed from the 
circle until there are no children left. In which order will the 
children be removed?</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline"><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">n</span></span></span></span></span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline"><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mi>n</mi></mrow><annotation encoding="application/x-tex">n</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.4306em;"></span><span class="mord mathnormal">n</span></span></span></span></span> integers: the removal order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline"><span class="katex"><span class="katex-mathml"><math xmlns="http://www.w3.org/1998/Math/MathML"><semantics><mrow><mn>1</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><mn>2</mn><mo>⋅</mo><mn>1</mn><msup><mn>0</mn><mn>5</mn></msup></mrow><annotation encoding="application/x-tex">1 \le n \le 2 \cdot 10^5</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.7804em; vertical-align: -0.136em;"></span><span class="mord">1</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 0.7719em; vertical-align: -0.136em;"></span><span class="mord mathnormal">n</span><span class="mspace" style="margin-right: 0.2778em;"></span><span class="mrel">≤</span><span class="mspace" style="margin-right: 0.2778em;"></span></span><span class="base"><span class="strut" style="height: 0.6444em;"></span><span class="mord">2</span><span class="mspace" style="margin-right: 0.2222em;"></span><span class="mbin">⋅</span><span class="mspace" style="margin-right: 0.2222em;"></span></span><span class="base"><span class="strut" style="height: 0.8141em;"></span><span class="mord">1</span><span class="mord"><span class="mord">0</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.8141em;"><span class="" style="top: -3.063em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight">5</span></span></span></span></span></span></span></span></span></span></span></span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7
</pre>
<p>Output:</p>
<pre>2 4 6 1 5 3 7
</pre></div>    </div>
    <div class="nav sidebar">
<h4>Sorting and Searching</h4>...
<a href="https://cses.fi/problemset/task/1141">Playlist<span class="task-score icon full"></span></a><a href="https://cses.fi/problemset/task/1073">Towers<span class="task-score icon full"></span></a><a href="https://cses.fi/problemset/task/1163">Traffic Lights<span class="task-score icon full"></span></a><a class="current" href="https://cses.fi/problemset/task/2162">Josephus Problem I<span class="task-score icon "></span></a><a href="https://cses.fi/problemset/task/2163">Josephus Problem II<span class="task-score icon "></span></a><a href="https://cses.fi/problemset/task/2168">Nested Ranges Check<span class="task-score icon "></span></a><a href="https://cses.fi/problemset/task/2169">Nested Ranges Count<span class="task-score icon "></span></a><a href="https://cses.fi/problemset/task/1164">Room Allocation<span class="task-score icon "></span></a>...
<hr>    <h4>Your submissions</h4>

    </div>
</div>
</div></body></html>