#include <WebServer.h>
#include "web_interface.h"
#include "definitions.h"
#include "deauth.h"
#include "applejuice.h"
WebServer server(80);
int num_networks;

// Move the function declaration to the top
String getEncryptionType(wifi_auth_mode_t encryptionType);

void redirect_root() {
  server.sendHeader("Location", "/");
  server.send(301);
}

void handle_root() {
    String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\">";
    html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
    html += "<title>WiFi-Deauther + AppleJuice</title><style>";
    html += ":root{--primary:#2563eb;--primary-dark:#1d4ed8;--danger:#dc2626;--danger-dark:#b91c1c;";
    html += "--success:#16a34a;--success-dark:#15803d;--warning:#ea580c;--warning-dark:#c2410c;";
    html += "--background:#f0f9ff;--card:#ffffff;--text:#1e293b;--text-light:#64748b;--border:#e2e8f0;";
    html += "--purple:#8b5cf6;--purple-dark:#7c3aed;--pink:#ec4899;--pink-dark:#db2777;--cyan:#06b6d4;--cyan-dark:#0891b2;}";
    html += "*{box-sizing:border-box;margin:0;padding:0;}";
    html += "body{font-family:Arial,sans-serif;line-height:1.6;color:var(--text);background-color:var(--background);padding:0;margin:0;transition:all 0.3s ease;}";
    html += ".container{max-width:1000px;margin:0 auto;padding:0 15px;}";
    html += "header{background:linear-gradient(135deg,var(--purple),var(--primary));color:white;padding:1.5rem 0;margin-bottom:2rem;box-shadow:0 4px 6px -1px rgba(0,0,0,0.1);}";
    html += "header h1{margin:0;font-size:1.8rem;text-align:center;text-shadow:1px 1px 3px rgba(0,0,0,0.3);}";
    html += ".card{background-color:var(--card);border-radius:12px;box-shadow:0 4px 6px rgba(0,0,0,0.07);margin-bottom:1.5rem;overflow:hidden;transition:transform 0.3s ease,box-shadow 0.3s ease;}";
    html += ".card:hover{transform:translateY(-3px);box-shadow:0 8px 15px rgba(0,0,0,0.1);}";
    html += ".card-header{background:linear-gradient(135deg,var(--primary),var(--purple));color:white;padding:1rem;font-weight:bold;font-size:1.2rem;display:flex;justify-content:space-between;align-items:center;text-shadow:1px 1px 2px rgba(0,0,0,0.2);}";
    html += ".card-body{padding:1.25rem;}";
    html += ".networks-table{width:100%;border-collapse:collapse;margin-bottom:1rem;border-radius:8px;overflow:hidden;}";
    html += ".networks-table th,.networks-table td{padding:0.75rem;text-align:left;border-bottom:1px solid var(--border);}";
    html += ".networks-table th{background:linear-gradient(135deg,var(--primary),var(--purple));color:white;text-shadow:1px 1px 2px rgba(0,0,0,0.2);}";
    html += ".networks-table tr:nth-child(even){background-color:rgba(0,0,0,0.02);}";
    html += ".networks-table tr:hover{background-color:rgba(0,0,0,0.05);cursor:pointer;}";
    html += ".form-group{margin-bottom:1.25rem;}";
    html += ".form-group label{display:block;margin-bottom:0.5rem;font-weight:bold;color:var(--primary);}";
    html += ".form-control{width:100%;padding:0.75rem;border:2px solid var(--border);border-radius:8px;font-size:1rem;transition:all 0.3s ease;}";
    html += ".form-control:focus{outline:none;border-color:var(--primary);box-shadow:0 0 0 3px rgba(37,99,235,0.1);}";
    html += "select.form-control{appearance:none;background-image:url(\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='16' height='16' viewBox='0 0 24 24' fill='none' stroke='%231e293b' stroke-width='2' stroke-linecap='round' stroke-linejoin='round'%3E%3Cpath d='M6 9l6 6 6-6'/%3E%3C/svg%3E\");background-repeat:no-repeat;background-position:right 0.75rem center;background-size:16px;padding-right:2.5rem;}";
    html += ".btn{display:inline-block;font-weight:500;text-align:center;white-space:nowrap;vertical-align:middle;user-select:none;border:none;padding:0.75rem 1.5rem;font-size:1rem;line-height:1.5;border-radius:8px;transition:all 0.2s ease-in-out;cursor:pointer;width:100%;box-shadow:0 2px 4px rgba(0,0,0,0.1);}";
    html += ".btn:focus{outline:0;box-shadow:0 0 0 3px rgba(37,99,235,0.25);}";
    html += ".btn:active{transform:translateY(1px);}";
    html += ".btn-primary{color:#fff;background:linear-gradient(135deg,var(--primary),var(--primary-dark));}";
    html += ".btn-primary:hover{background:linear-gradient(135deg,var(--primary-dark),var(--primary));}";
    html += ".btn-danger{color:#fff;background:linear-gradient(135deg,var(--danger),var(--danger-dark));}";
    html += ".btn-danger:hover{background:linear-gradient(135deg,var(--danger-dark),var(--danger));}";
    html += ".btn-success{color:#fff;background:linear-gradient(135deg,var(--success),var(--success-dark));}";
    html += ".btn-success:hover{background:linear-gradient(135deg,var(--success-dark),var(--success));}";
    html += ".btn-warning{color:#fff;background:linear-gradient(135deg,var(--warning),var(--warning-dark));}";
    html += ".btn-warning:hover{background:linear-gradient(135deg,var(--warning-dark),var(--warning));}";
    html += ".btn-purple{color:#fff;background:linear-gradient(135deg,var(--purple),var(--purple-dark));}";
    html += ".btn-purple:hover{background:linear-gradient(135deg,var(--purple-dark),var(--purple));}";
    html += ".btn-cyan{color:#fff;background:linear-gradient(135deg,var(--cyan),var(--cyan-dark));}";
    html += ".btn-cyan:hover{background:linear-gradient(135deg,var(--cyan-dark),var(--cyan));}";
    html += ".tabs{display:flex;flex-wrap:wrap;margin-bottom:1.5rem;border-bottom:1px solid var(--border);background-color:white;border-radius:8px 8px 0 0;padding:0.5rem 0.5rem 0 0.5rem;}";
    html += ".tab-btn{padding:0.75rem 1.5rem;background:none;border:none;border-bottom:2px solid transparent;cursor:pointer;font-weight:500;color:var(--text-light);transition:all 0.3s ease;border-radius:8px 8px 0 0;}";
    html += ".tab-btn:hover{color:var(--primary);background-color:rgba(37,99,235,0.05);}";
    html += ".tab-btn.active{color:var(--primary);border-bottom-color:var(--primary);background-color:rgba(37,99,235,0.1);}";
    html += ".tab-content{display:none;}";
    html += ".tab-content.active{display:block;animation:fadeIn 0.5s ease;}";
    html += ".badge{display:inline-block;padding:0.25rem 0.5rem;font-size:0.75rem;font-weight:700;line-height:1;text-align:center;white-space:nowrap;vertical-align:baseline;border-radius:0.25rem;color:white;}";
    html += ".badge-success{background:linear-gradient(135deg,var(--success),var(--success-dark));}";
    html += ".badge-danger{background:linear-gradient(135deg,var(--danger),var(--danger-dark));}";
    html += ".badge-warning{background:linear-gradient(135deg,var(--warning),var(--warning-dark));}";
    html += ".badge-primary{background:linear-gradient(135deg,var(--primary),var(--primary-dark));}";
    html += ".badge-purple{background:linear-gradient(135deg,var(--purple),var(--purple-dark));}";
    html += ".status-indicator{display:flex;align-items:center;margin-bottom:1rem;padding:0.75rem;border-radius:8px;background-color:rgba(0,0,0,0.05);}";
    html += ".status-indicator-dot{width:12px;height:12px;border-radius:50%;margin-right:0.5rem;}";
    html += ".status-indicator-dot.active{background-color:var(--success);box-shadow:0 0 0 3px rgba(22,163,74,0.2);animation:pulse 1.5s infinite;}";
    html += ".status-indicator-dot.inactive{background-color:var(--text-light);}";
    html += ".footer{text-align:center;padding:2rem 0;color:var(--text-light);font-size:0.9rem;border-top:1px solid var(--border);margin-top:2rem;background-color:white;border-radius:8px;}";
    html += ".footer a{color:var(--primary);text-decoration:none;transition:color 0.3s ease;}";
    html += ".footer a:hover{color:var(--primary-dark);text-decoration:underline;}";
    html += ".signal-bars{display:inline-block;width:20px;}";
    html += ".signal-bars .bar{display:inline-block;width:4px;margin-right:1px;background-color:var(--success);border-radius:1px;}";
    html += ".signal-bars .bar-1{height:3px;}";
    html += ".signal-bars .bar-2{height:6px;}";
    html += ".signal-bars .bar-3{height:9px;}";
    html += ".signal-bars .bar-4{height:12px;}";
    html += ".signal-bars.weak .bar{background-color:var(--danger);}";
    html += ".signal-bars.weak .bar-3,.signal-bars.weak .bar-4{background-color:rgba(0,0,0,0.1);}";
    html += ".signal-bars.medium .bar{background-color:var(--warning);}";
    html += ".signal-bars.medium .bar-4{background-color:rgba(0,0,0,0.1);}";
    html += ".security-icon{display:inline-flex;align-items:center;justify-content:center;width:24px;height:24px;border-radius:50%;background-color:var(--primary);color:white;font-size:12px;font-weight:bold;margin-right:5px;}";
    html += ".security-icon.open{background-color:var(--danger);}";
    html += ".security-icon.wpa{background-color:var(--warning);}";
    html += ".security-icon.wpa2{background-color:var(--success);}";
    html += "@keyframes pulse{0%{box-shadow:0 0 0 0 rgba(22,163,74,0.4);}70%{box-shadow:0 0 0 6px rgba(22,163,74,0);}100%{box-shadow:0 0 0 0 rgba(22,163,74,0);}}";
    html += "@keyframes fadeIn{from{opacity:0;transform:translateY(10px);}to{opacity:1;transform:translateY(0);}}";
    html += "@media (max-width:768px){.card-header{padding:0.75rem;font-size:1rem;}.btn{padding:0.6rem 1.2rem;}.tab-btn{padding:0.6rem 1rem;font-size:0.9rem;}.networks-table th,.networks-table td{padding:0.5rem;font-size:0.9rem;}}";
    html += "@media (max-width:576px){.tab-btn{flex:1 0 auto;text-align:center;font-size:0.8rem;padding:0.5rem;}.card-header{flex-direction:column;text-align:center;}.networks-table{font-size:0.8rem;}}";
    html += "</style></head><body>";
    
    html += "<header><div class=\"container\"><h1>WiFi-Deauther + AppleJuice</h1></div></header>";
    html += "<div class=\"container\">";
    html += "<div class=\"tabs\">";
    html += "<button class=\"tab-btn active\" onclick=\"openTab(event,'networks')\">Networks</button>";
    html += "<button class=\"tab-btn\" onclick=\"openTab(event,'attacks')\">Attacks</button>";
    html += "<button class=\"tab-btn\" onclick=\"openTab(event,'reason-codes')\">Reason Codes</button>";
    html += "</div>";
    
    html += "<div id=\"networks\" class=\"tab-content active\">";
    html += "<div class=\"card\">";
    html += "<div class=\"card-header\">Available WiFi Networks";
    html += "<form method=\"post\" action=\"/rescan\" style=\"display:inline;margin:0;\">";
    html += "<button type=\"submit\" class=\"btn btn-danger\" style=\"width:auto;padding:0.3rem 0.8rem;font-size:0.8rem;\">Rescan</button>";
    html += "</form></div>";
    html += "<div class=\"card-body\">";
    html += "<div style=\"max-height:400px;overflow-y:auto;\">";
    html += "<table class=\"networks-table\">";
    html += "<thead><tr><th>No.</th><th>SSID</th><th>BSSID</th><th>CH</th><th>Signal</th><th>Security</th></tr></thead>";
    html += "<tbody>";
    
    for (int i = 0; i < num_networks; i++) {
      String encryption = getEncryptionType(WiFi.encryptionType(i));
      String rssiClass = "";
      String signalBars = "";
      String securityIcon = "";
      
      // Signal strength visualization
      int rssi = WiFi.RSSI(i);
      if (rssi > -50) {
        rssiClass = "badge-success";
        signalBars = "<div class='signal-bars strong'><span class='bar bar-1'></span><span class='bar bar-2'></span><span class='bar bar-3'></span><span class='bar bar-4'></span></div>";
      } else if (rssi > -70) {
        rssiClass = "badge-warning";
        signalBars = "<div class='signal-bars medium'><span class='bar bar-1'></span><span class='bar bar-2'></span><span class='bar bar-3'></span><span class='bar bar-4'></span></div>";
      } else {
        rssiClass = "badge-danger";
        signalBars = "<div class='signal-bars weak'><span class='bar bar-1'></span><span class='bar bar-2'></span><span class='bar bar-3'></span><span class='bar bar-4'></span></div>";
      }
      
      // Security icon
      if (encryption == "Open") {
        securityIcon = "<span class='security-icon open'>O</span>";
      } else if (encryption.indexOf("WPA2") >= 0) {
        securityIcon = "<span class='security-icon wpa2'>2</span>";
      } else if (encryption.indexOf("WPA") >= 0) {
        securityIcon = "<span class='security-icon wpa'>W</span>";
      } else {
        securityIcon = "<span class='security-icon'>?</span>";
      }
      
      html += "<tr data-network='" + String(i) + "' onclick=\"selectNetwork(" + String(i) + ")\">";
      html += "<td>" + String(i) + "</td>";
      html += "<td>" + WiFi.SSID(i) + "</td>";
      html += "<td>" + WiFi.BSSIDstr(i) + "</td>";
      html += "<td>" + String(WiFi.channel(i)) + "</td>";
      html += "<td>" + signalBars + " <span class='badge " + rssiClass + "'>" + String(rssi) + " dBm</span></td>";
      html += "<td>" + securityIcon + encryption + "</td>";
      html += "</tr>";
    }
    
    html += "</tbody></table></div>";
    html += "<div class=\"status-indicator\">";
    html += "<div class=\"status-indicator-dot inactive\" id=\"status-dot\"></div>";
    html += "<span>Eliminated stations: <strong>" + String(eliminated_stations) + "</strong></span>";
    html += "</div></div></div></div>";
    
    html += "<div id=\"attacks\" class=\"tab-content\">";
    html += "<div class=\"card\">";
    html += "<div class=\"card-header\">Launch Deauth Attack</div>";
    html += "<div class=\"card-body\">";
    html += "<form method=\"post\" action=\"/deauth\">";
    html += "<div class=\"form-group\">";
    html += "<label for=\"net_num\">Select Network:</label>";
    html += "<select class=\"form-control\" name=\"net_num\" id=\"net_num\" required>";
    html += "<option value=\"\">-- Select Network --</option>";
    
    for (int i = 0; i < num_networks; i++) {
      html += "<option value='" + String(i) + "'>" + String(i) + ": " + WiFi.SSID(i) + "</option>";
    }
    
    html += "</select></div>";
    html += "<div class=\"form-group\">";
    html += "<label for=\"reason\">Reason Code:</label>";
    html += "<select class=\"form-control\" name=\"reason\" id=\"reason\" required>";
    html += "<option value=\"\">-- Select Reason Code --</option>";
    html += "<option value=\"1\">1: Unspecified reason</option>";
    html += "<option value=\"2\">2: Previous authentication no longer valid</option>";
    html += "<option value=\"3\">3: Deauthenticated because sending STA is leaving</option>";
    html += "<option value=\"4\">4: Disassociated due to inactivity</option>";
    html += "<option value=\"5\">5: Disassociated because WAP cannot handle all STAs</option>";
    html += "<option value=\"6\">6: Class 2 frame received from nonauthenticated STA</option>";
    html += "<option value=\"7\">7: Class 3 frame received from nonassociated STA</option>";
    html += "<option value=\"8\">8: Disassociated because sending STA is leaving BSS</option>";
    html += "<option value=\"9\">9: STA requesting association is not authenticated</option>";
    html += "</select></div>";
    html += "<button type=\"submit\" class=\"btn btn-danger\">Launch Attack</button>";
    html += "</form></div></div>";
    
    html += "<div class=\"card\">";
    html += "<div class=\"card-header\">Deauth All Networks</div>";
    html += "<div class=\"card-body\">";
    html += "<form method=\"post\" action=\"/deauth_all\">";
    html += "<div class=\"form-group\">";
    html += "<label for=\"reason-all\">Reason Code:</label>";
    html += "<select class=\"form-control\" name=\"reason\" id=\"reason-all\" required>";
    html += "<option value=\"\">-- Select Reason Code --</option>";
    html += "<option value=\"1\">1: Unspecified reason</option>";
    html += "<option value=\"2\">2: Previous authentication no longer valid</option>";
    html += "<option value=\"3\">3: Deauthenticated because sending STA is leaving</option>";
    html += "<option value=\"4\">4: Disassociated due to inactivity</option>";
    html += "<option value=\"5\">5: Disassociated because WAP cannot handle all STAs</option>";
    html += "<option value=\"6\">6: Class 2 frame received from nonauthenticated STA</option>";
    html += "<option value=\"7\">7: Class 3 frame received from nonassociated STA</option>";
    html += "<option value=\"8\">8: Disassociated because sending STA is leaving BSS</option>";
    html += "<option value=\"9\">9: STA requesting association is not authenticated</option>";
    html += "</select></div>";
    html += "<button type=\"submit\" class=\"btn btn-danger\">Deauth All Networks</button>";
    html += "</form></div></div>";
    
    html += "<div class=\"card\">";
    html += "<div class=\"card-header\">Attack Controls</div>";
    html += "<div class=\"card-body\">";
    html += "<div class=\"form-group\">";
    html += "<form method=\"post\" action=\"/stop\">";
    html += "<button type=\"submit\" class=\"btn btn-primary\">Stop Deauth Attack</button>";
    html += "</form></div>";
    html += "<div class=\"form-group\">";
    html += "<form method=\"post\" action=\"/applejuice\">";
    html += "<button type=\"submit\" class=\"btn btn-purple\">Start Applejuice Attack</button>";
    html += "</form></div>";
    html += "<div class=\"form-group\">";
    html += "<form method=\"post\" action=\"/stop_applejuice\">";
    html += "<button type=\"submit\" class=\"btn btn-cyan\">Stop Applejuice Attack</button>";
    html += "</form></div>";
    html += "</div></div></div>";
    
    html += "<div id=\"reason-codes\" class=\"tab-content\">";
    html += "<div class=\"card\">";
    html += "<div class=\"card-header\">Deauthentication Reason Codes</div>";
    html += "<div class=\"card-body\">";
    html += "<div style=\"max-height:500px;overflow-y:auto;\">";
    html += "<table class=\"networks-table\">";
    html += "<thead><tr><th>Code</th><th>Meaning</th></tr></thead>";
    html += "<tbody>";
    html += "<tr><td>0</td><td>Reserved.</td></tr>";
    html += "<tr><td>1</td><td>Unspecified reason.</td></tr>";
    html += "<tr><td>2</td><td>Previous authentication no longer valid.</td></tr>";
    html += "<tr><td>3</td><td>Deauthenticated because sending station (STA) is leaving or has left Independent Basic Service Set (IBSS) or ESS.</td></tr>";
    html += "<tr><td>4</td><td>Disassociated due to inactivity.</td></tr>";
    html += "<tr><td>5</td><td>Disassociated because WAP device is unable to handle all currently associated STAs.</td></tr>";
    html += "<tr><td>6</td><td>Class 2 frame received from nonauthenticated STA.</td></tr>";
    html += "<tr><td>7</td><td>Class 3 frame received from nonassociated STA.</td></tr>";
    html += "<tr><td>8</td><td>Disassociated because sending STA is leaving or has left Basic Service Set (BSS).</td></tr>";
    html += "<tr><td>9</td><td>STA requesting (re)association is not authenticated with responding STA.</td></tr>";
    html += "<tr><td>10</td><td>Disassociated because the information in the Power Capability element is unacceptable.</td></tr>";
    html += "<tr><td>11</td><td>Disassociated because the information in the Supported Channels element is unacceptable.</td></tr>";
    html += "<tr><td>12</td><td>Disassociated due to BSS Transition Management.</td></tr>";
    html += "<tr><td>13</td><td>Invalid element, that is, an element defined in this standard for which the content does not meet the specifications in Clause 8.</td></tr>";
    html += "<tr><td>14</td><td>Message integrity code (MIC) failure.</td></tr>";
    html += "<tr><td>15</td><td>4-Way Handshake timeout.</td></tr>";
    html += "<tr><td>16</td><td>Group Key Handshake timeout.</td></tr>";
    html += "<tr><td>17</td><td>Element in 4-Way Handshake different from (Re)Association Request/ Probe Response/Beacon frame.</td></tr>";
    html += "<tr><td>18</td><td>Invalid group cipher.</td></tr>";
    html += "<tr><td>19</td><td>Invalid pairwise cipher.</td></tr>";
    html += "<tr><td>20</td><td>Invalid AKMP.</td></tr>";
    html += "<tr><td>21</td><td>Unsupported RSNE version.</td></tr>";
    html += "<tr><td>22</td><td>Invalid RSNE capabilities.</td></tr>";
    html += "<tr><td>23</td><td>IEEE 802.1X authentication failed.</td></tr>";
    html += "<tr><td>24</td><td>Cipher suite rejected because of the security policy.</td></tr>";
    html += "</tbody></table></div></div></div></div>";
    
    html += "<div class=\"footer\">";
    html += "<p>Original Source: <a href=\"https://github.com/electronicminer/ESP32-s3-Deauther-master-with-apple-juice\" target=\"_blank\">https://github.com/electronicminer/ESP32-s3-Deauther-master-with-apple-juice</a></p>";
    html += "<p>Web_interface edit by Iddox</p>";
    html += "</div>";
    html += "</div>";
    
    html += "<script>";
    html += "function openTab(evt,tabName){";
    html += "var i,tabcontent,tablinks;";
    html += "tabcontent=document.getElementsByClassName('tab-content');";
    html += "for(i=0;i<tabcontent.length;i++){";
    html += "tabcontent[i].className=tabcontent[i].className.replace(' active','');}";
    html += "tablinks=document.getElementsByClassName('tab-btn');";
    html += "for(i=0;i<tablinks.length;i++){";
    html += "tablinks[i].className=tablinks[i].className.replace(' active','');}";
    html += "document.getElementById(tabName).className+=' active';";
    html += "evt.currentTarget.className+=' active';}";
    html += "function selectNetwork(networkId){";
    html += "document.getElementById('net_num').value=networkId;";
    html += "openTab({currentTarget:document.querySelector('.tab-btn:nth-child(2)')}, 'attacks');}";
    html += "document.addEventListener('DOMContentLoaded',function(){";
    html += "var eliminatedStations=" + String(eliminated_stations) + ";";
    html += "var statusDot=document.getElementById('status-dot');";
    html += "if(eliminatedStations>0){";
    html += "statusDot.classList.remove('inactive');";
    html += "statusDot.classList.add('active');}});";
    html += "</script></body></html>";
    
    server.send(200, "text/html", html);
}

void handle_deauth() {
  int wifi_number = server.arg("net_num").toInt();
  uint16_t reason = server.arg("reason").toInt();

  String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<title>Deauth Attack</title><style>";
  html += ":root{--primary:#2563eb;--primary-dark:#1d4ed8;--danger:#dc2626;--success:#16a34a;--background:#f0f9ff;--purple:#8b5cf6;}";
  html += "*{box-sizing:border-box;margin:0;padding:0;}";
  html += "body{font-family:Arial,sans-serif;display:flex;justify-content:center;align-items:center;min-height:100vh;background-color:var(--background);padding:20px;}";
  html += ".alert-container{width:100%;max-width:500px;text-align:center;animation:slideIn 0.5s ease;}";
  html += ".alert{background:linear-gradient(135deg,var(--success),var(--primary));color:white;padding:2rem;border-radius:12px;box-shadow:0 8px 15px rgba(0,0,0,0.1);margin-bottom:1.5rem;}";
  html += ".alert.error{background:linear-gradient(135deg,var(--danger),var(--purple));}";
  html += ".alert h2{margin-bottom:1rem;font-size:1.5rem;text-shadow:1px 1px 2px rgba(0,0,0,0.2);}";
  html += ".alert p{margin-bottom:0.5rem;opacity:0.9;}";
  html += ".button{display:inline-block;padding:0.75rem 1.5rem;background:linear-gradient(135deg,var(--primary),var(--purple));color:white;text-decoration:none;border-radius:8px;font-weight:500;transition:all 0.3s ease;box-shadow:0 4px 6px rgba(0,0,0,0.1);}";
  html += ".button:hover{background:linear-gradient(135deg,var(--purple),var(--primary));transform:translateY(-2px);box-shadow:0 6px 10px rgba(0,0,0,0.15);}";
  html += "@keyframes slideIn{from{opacity:0;transform:translateY(-20px);}to{opacity:1;transform:translateY(0);}}";
  html += "@keyframes pulse{0%{box-shadow:0 0 0 0 rgba(220,38,38,0.7);}70%{box-shadow:0 0 0 10px rgba(220,38,38,0);}100%{box-shadow:0 0 0 0 rgba(220,38,38,0);}}";
  html += ".pulse{animation:pulse 2s infinite;}";
  html += ".footer{text-align:center;margin-top:2rem;color:var(--primary-dark);font-size:0.8rem;}";
  html += ".footer a{color:var(--primary);text-decoration:none;}";
  html += ".footer a:hover{text-decoration:underline;}";
  html += "</style></head><body><div class=\"alert-container\">";

  if (wifi_number < num_networks) {
    html += "<div class=\"alert pulse\">";
    html += "<h2>Starting Deauth Attack!</h2>";
    html += "<p>Target Network: <strong>" + WiFi.SSID(wifi_number) + "</strong></p>";
    html += "<p>Network Number: <strong>" + String(wifi_number) + "</strong></p>";
    html += "<p>Reason Code: <strong>" + String(reason) + "</strong></p>";
    html += "</div>";
    start_deauth(wifi_number, DEAUTH_TYPE_SINGLE, reason);
  } else {
    html += "<div class=\"alert error\">";
    html += "<h2>Error: Invalid Network Number</h2>";
    html += "<p>Please select a valid network number.</p>";
    html += "</div>";
  }

  html += "<a href=\"/\" class=\"button\">Back to Dashboard</a>";
  html += "<div class=\"footer\">";
  html += "<p>Web_interface edit by Iddox</p>";
  html += "</div>";
  html += "</div><script>setTimeout(function(){window.location.href='/';},3000);</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handle_deauth_all() {
  uint16_t reason = server.arg("reason").toInt();

  String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<title>Deauth All Networks</title><style>";
  html += ":root{--warning:#ea580c;--background:#f0f9ff;--danger:#dc2626;}";
  html += "*{box-sizing:border-box;margin:0;padding:0;}";
  html += "body{font-family:Arial,sans-serif;display:flex;justify-content:center;align-items:center;min-height:100vh;background-color:var(--background);padding:20px;}";
  html += ".alert-container{width:100%;max-width:500px;text-align:center;animation:slideIn 0.5s ease;}";
  html += ".alert{background:linear-gradient(135deg,var(--danger),var(--warning));color:white;padding:2rem;border-radius:12px;box-shadow:0 8px 15px rgba(0,0,0,0.1);margin-bottom:1.5rem;}";
  html += ".alert h2{margin-bottom:1rem;font-size:1.5rem;text-shadow:1px 1px 2px rgba(0,0,0,0.2);}";
  html += ".alert p{margin-bottom:0.5rem;opacity:0.9;}";
  html += "@keyframes slideIn{from{opacity:0;transform:translateY(-20px);}to{opacity:1;transform:translateY(0);}}";
  html += "@keyframes blink{0%,100%{opacity:1;}50%{opacity:0.5;}}";
  html += ".blink{animation:blink 1s infinite;}";
  html += ".countdown{font-size:2.5rem;font-weight:bold;margin:1rem 0;text-shadow:2px 2px 4px rgba(0,0,0,0.2);}";
  html += ".footer{text-align:center;margin-top:2rem;color:white;font-size:0.8rem;}";
  html += "</style></head><body>";
  html += "<div class=\"alert-container\">";
  html += "<div class=\"alert\">";
  html += "<h2 class=\"blink\">WARNING: Deauth Attack on All Networks!</h2>";
  html += "<p>WiFi will shut down now. To stop the attack, please reset the ESP32.</p>";
  html += "<p>Reason code: <strong>" + String(reason) + "</strong></p>";
  html += "<div class=\"countdown\" id=\"countdown\">5</div>";
  html += "<p>Redirecting...</p>";
  html += "<div class=\"footer\">";
  html += "<p>Web_interface edit by Iddox</p>";
  html += "</div>";
  html += "</div></div>";
  html += "<script>";
  html += "var seconds=5;";
  html += "var countdownEl=document.getElementById('countdown');";
  html += "var interval=setInterval(function(){";
  html += "seconds--;";
  html += "countdownEl.textContent=seconds;";
  html += "if(seconds<=0){clearInterval(interval);}";
  html += "},1000);";
  html += "</script></body></html>";

  server.send(200, "text/html", html);
  server.stop();
  start_deauth(0, DEAUTH_TYPE_ALL, reason);
}

void handle_applejuice() {
  start_attack_task();

  String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<title>Applejuice Control</title><style>";
  html += ":root{--primary:#2563eb;--success:#16a34a;--background:#f0f9ff;--purple:#8b5cf6;}";
  html += "*{box-sizing:border-box;margin:0;padding:0;}";
  html += "body{font-family:Arial,sans-serif;display:flex;justify-content:center;align-items:center;min-height:100vh;background-color:var(--background);padding:20px;}";
  html += ".alert-container{width:100%;max-width:500px;text-align:center;animation:slideIn 0.5s ease;}";
  html += ".alert{background:linear-gradient(135deg,var(--purple),var(--success));color:white;padding:2rem;border-radius:12px;box-shadow:0 8px 15px rgba(0,0,0,0.1);margin-bottom:1.5rem;}";
  html += ".alert h2{margin-bottom:1rem;font-size:1.5rem;text-shadow:1px 1px 2px rgba(0,0,0,0.2);}";
  html += ".button{display:inline-block;padding:0.75rem 1.5rem;background:linear-gradient(135deg,var(--primary),var(--purple));color:white;text-decoration:none;border-radius:8px;font-weight:500;transition:all 0.3s ease;box-shadow:0 4px 6px rgba(0,0,0,0.1);}";
  html += ".button:hover{background:linear-gradient(135deg,var(--purple),var(--primary));transform:translateY(-2px);box-shadow:0 6px 10px rgba(0,0,0,0.15);}";
  html += ".loading-circle{width:60px;height:60px;margin:0 auto 1rem;border:5px solid rgba(255,255,255,0.3);border-radius:50%;border-top-color:white;animation:spin 1s linear infinite;}";
  html += "@keyframes slideIn{from{opacity:0;transform:translateY(-20px);}to{opacity:1;transform:translateY(0);}}";
  html += "@keyframes spin{from{transform:rotate(0deg);}to{transform:rotate(360deg);}}";
  html += ".footer{text-align:center;margin-top:2rem;color:white;font-size:0.8rem;}";
  html += "</style></head><body>";
  html += "<div class=\"alert-container\">";
  html += "<div class=\"alert\">";
  html += "<div class=\"loading-circle\"></div>";
  html += "<h2>Applejuice Attack Activated!</h2>";
  html += "<p>The attack is now running...</p>";
  html += "<div class=\"footer\">";
  html += "<p>Web_interface edit by Iddox</p>";
  html += "</div>";
  html += "</div>";
  html += "<a href=\"/\" class=\"button\">Back to Dashboard</a>";
  html += "</div>";
  html += "<script>setTimeout(function(){window.location.href='/';},3000);</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handle_stop_applejuice() {
  stop_attack_task();

  String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<title>Stop Applejuice</title><style>";
  html += ":root{--primary:#2563eb;--danger:#dc2626;--background:#f0f9ff;--cyan:#06b6d4;}";
  html += "*{box-sizing:border-box;margin:0;padding:0;}";
  html += "body{font-family:Arial,sans-serif;display:flex;justify-content:center;align-items:center;min-height:100vh;background-color:var(--background);padding:20px;}";
  html += ".alert-container{width:100%;max-width:500px;text-align:center;animation:slideIn 0.5s ease;}";
  html += ".alert{background:linear-gradient(135deg,var(--cyan),var(--primary));color:white;padding:2rem;border-radius:12px;box-shadow:0 8px 15px rgba(0,0,0,0.1);margin-bottom:1.5rem;}";
  html += ".alert h2{margin-bottom:1rem;font-size:1.5rem;text-shadow:1px 1px 2px rgba(0,0,0,0.2);}";
  html += ".button{display:inline-block;padding:0.75rem 1.5rem;background:linear-gradient(135deg,var(--primary),var(--cyan));color:white;text-decoration:none;border-radius:8px;font-weight:500;transition:all 0.3s ease;box-shadow:0 4px 6px rgba(0,0,0,0.1);}";
  html += ".button:hover{background:linear-gradient(135deg,var(--cyan),var(--primary));transform:translateY(-2px);box-shadow:0 6px 10px rgba(0,0,0,0.15);}";
  html += ".checkmark{width:60px;height:60px;border-radius:50%;display:block;stroke-width:2;stroke:white;stroke-miterlimit:10;margin:0 auto 1rem;box-shadow:inset 0px 0px 0px white;}";
  html += ".checkmark-circle{stroke-dasharray:166;stroke-dashoffset:166;stroke-width:2;stroke-miterlimit:10;stroke:white;fill:none;animation:stroke 0.6s cubic-bezier(0.65,0,0.45,1) forwards;}";
  html += ".checkmark-check{transform-origin:50% 50%;stroke-dasharray:48;stroke-dashoffset:48;animation:stroke 0.3s cubic-bezier(0.65,0,0.45,1) 0.8s forwards;}";
  html += "@keyframes slideIn{from{opacity:0;transform:translateY(-20px);}to{opacity:1;transform:translateY(0);}}";
  html += "@keyframes stroke{100%{stroke-dashoffset:0;}}";
  html += ".footer{text-align:center;margin-top:2rem;color:white;font-size:0.8rem;}";
  html += "</style></head><body>";
  html += "<div class=\"alert-container\">";
  html += "<div class=\"alert\">";
  html += "<svg class=\"checkmark\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 52 52\">";
  html += "<circle class=\"checkmark-circle\" cx=\"26\" cy=\"26\" r=\"25\" fill=\"none\"/>";
  html += "<path class=\"checkmark-check\" fill=\"none\" d=\"M14.1 27.2l7.1 7.2 16.7-16.8\"/>";
  html += "</svg>";
  html += "<h2>Applejuice Attack Stopped!</h2>";
  html += "<p>The attack has been successfully terminated.</p>";
  html += "<div class=\"footer\">";
  html += "<p>Web_interface edit by Iddox</p>";
  html += "</div>";
  html += "</div>";
  html += "<a href=\"/\" class=\"button\">Back to Dashboard</a>";
  html += "</div>";
  html += "<script>setTimeout(function(){window.location.href='/';},3000);</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handle_rescan() {
  num_networks = WiFi.scanNetworks();
  redirect_root();
}

void handle_stop() {
  stop_deauth();
  redirect_root();
}

void start_web_interface() {
  server.on("/", handle_root);
  server.on("/deauth", handle_deauth);
  server.on("/deauth_all", handle_deauth_all);
  server.on("/rescan", handle_rescan);
  server.on("/stop", handle_stop);
  server.on("/applejuice", handle_applejuice);
  server.on("/stop_applejuice", handle_stop_applejuice);
  server.begin();
}

void web_interface_handle_client() {
  server.handleClient();
}

String getEncryptionType(wifi_auth_mode_t encryptionType) {
  switch (encryptionType) {
    case WIFI_AUTH_OPEN:
      return "Open";
    case WIFI_AUTH_WEP:
      return "WEP";
    case WIFI_AUTH_WPA_PSK:
      return "WPA_PSK";
    case WIFI_AUTH_WPA2_PSK:
      return "WPA2_PSK";
    case WIFI_AUTH_WPA_WPA2_PSK:
      return "WPA_WPA2_PSK";
    case WIFI_AUTH_WPA2_ENTERPRISE:
      return "WPA2_ENTERPRISE";
    default:
      return "UNKNOWN";
  }
}
