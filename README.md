# Platforma mobilă cu elemente animatronice

## Descriere generală
Proiectul constă în realizarea unui robot mobil pe șasiu 4WD, controlat wireless, care integrează două elemente mecanice animate sub forma unor fluturi cu aripi mobile. Platforma mobilă este alcătuită din patru motoare DC cu reductor, montate câte unul pe fiecare roată. Deplasarea se realizează prin control diferențial stânga–dreapta, permițând mișcări înainte, înapoi și rotație pe loc cu o telecomandă. Cele două comunica prin modulul radio nRF24L01.

Elementele mecanice ale proiectului sunt fluturii, acționați de câte un motor DC cu reductor de tip N20. Motorul antrenează un mecanism de conversie rotație–translație (excentric-bielă), care transformă mișcarea continuă de rotație în mișcare alternativă a aripilor. Această soluție permite obținerea unei frecvențe constante de bătaie a aripilor, controlabilă prin variația semnalului PWM.

Proiectul demonstrează integrarea controlului electronic, a mecanismelor simple și a comunicației wireless într-un sistem funcțional coerent, fără a depinde de modele aerodinamice complexe.

## Componente

| Componentă | Cantitate | Rol |
| :--- | :---: | :--- |
| **ELECTRONICE** | | |
| [Driver motor, tip TB6612FNG](https://www.emag.ro/driver-motor-tip-tb6612fng-ai0383-s299/pd/D6QW8GMBM/?ref=history-shopping_465680196_236249_1) | 1 | Controlul motoarelor de pe șasiu. [Datasheet](https://cdn.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf) |
| [Șasiu masina 4wd](https://www.emag.ro/sasiu-dublu-masina-inteligenta-cu-4-roti-3874784221220/pd/DWKRZKYBM/?ref=history-shopping_465680196_157633_1) | 1 | Platforma de locomoție |
| [Plăcă Arduino Nano](https://www.optimusdigital.ro/ro/compatibile-cu-arduino-nano/1686-placa-de-dezvoltare-compatibila-cu-arduino-nano-atmega328p-i-ch340.html?search_query=Placa+de+Dezvoltare+compatibila+cu+Arduino+Nano+%28ATmega328p+%C8%99i+CH340%29+++Cablu+30+cm&results=5) | 2 | <ul><li>Unitatea centrală de procesare a robotului</li><li>Unitatea de procesare a telecomenzii</li></ul> |
| [Placă Arduino Uno](https://www.optimusdigital.ro/ro/placi-avr/4561-placa-de-dezvoltare-compatibila-cu-arduino-uno-r3-atmega328p-atmega16u2-cablu-50-cm.html?search_query=Placa+de+Dezvoltare+Compatibila+cu+Arduino+UNO+R3+%28ATmega328p+++ATmega16u2%29+++Cablu+50+cm&results=1) | 1 | Unitatea de procesare a efectelor audio și luminoase |
| [Joystick](https://www.optimusdigital.ro/ro/senzori-senzori-de-atingere/742-modul-joystick-ps2-biaxial-negru-cu-5-pini.html?search_query=joystick&results=28) | 1 | Interfața de control a direcției și vitezei |
| [Modul Transceiver nRF24L01 (2.4 GHz)](https://www.optimusdigital.ro/ro/ism-24-ghz/48-modul-tranceiver-nrf24l01-24-ghz.html?search_query=Modul+Transceiver+nRF24L01+%282.4+GHz%29&results=5) | 2 | Comunicare wireless bidirecțională |
| [Placă adaptoare modul wireless NRF24L01](https://www.emag.ro/placa-adaptor-modul-wireless-nrf24l01-alimentare-4-5v-9v-3-3v-dh000023/pd/DW8QQL3BM/?ref=history-shopping_471325353_245879_1) | 2 | Adaptor tensiune și stabilitate pentru radio |
| [Micro Motor GA12-N20 (Reductor 1:30)](https://www.optimusdigital.ro/ro/motoare-micro-motoare-cu-reductor/678-micro-motor-cu-reductor-ga12-n20-130.html?search_query=Micro+Motor+GA12-N20+cu+Reductor+1%3A30+%C8%99i+Ax+de+10+mm&results=7) | 1 | Acționarea aripilor fluturelui mic |
| [Micro Motor GA12-N20 (Reductor 1:10)](https://www.optimusdigital.ro/ro/motoare-micro-motoare-cu-reductor/676-micro-motor-cu-reductor-ga12-n20-110.html?search_query=Micro+Motor+GA12-N20+cu+Reductor+1%3A10+%C8%99i+Ax+de+10+mm&results=7) | 1 | Acționarea aripilor fluturelui mare |
| [Breadboard 400 puncte](https://www.emag.ro/breadboard-400-puncte-ai059-s69/pd/DRJ66JBBM/?ref=history-shopping_465680196_38837_1) | 2 | Prototipare conexiuni |
| [Breadboard 830 puncte](https://www.emag.ro/breadboard-830-puncte-mb102-ai067-s70/pd/DF0C5JBBM/?ref=history-shopping_465680196_34366_1) | 1 | Prototipare conexiuni |
| [Mini breadboard 170 puncte](https://www.optimusdigital.ro/ro/prototipare-breadboard-uri/244-mini-breadboard-colorat.html?search_query=Mini+Breadboard+Alb&results=17) | 1 | Prototipare conexiuni |
| [Mufe baterie 9V](https://www.emag.ro/mufa-baterie-9v-conector-ai686-s262/pd/D9ZZ5JBBM/?ref=history-shopping_465680196_34366_2) | 5 | Conexiune alimentare |
| [Comutator KCD10-101 (ON/OFF)](https://www.optimusdigital.ro/ro/butoane-i-comutatoare/7377-comutator-kcd10-101.html?search_query=Comutator+KCD10-101&results=1) | 1 | Întrerupător general |
| [Buzzer pasiv](https://www.optimusdigital.ro/ro/audio-buzzere/634-buzzer-pasiv-de-5-v.html?search_query=Buzzer+Pasiv+de+5+V&results=9) | 1 | Semnalizare sonoră |
| [Tranzistori NPN 2n2222](https://www.optimusdigital.ro/ro/componente-electronice-tranzistoare/935-tranzistor-s9013-npn-50-pcs-set.html?search_query=Tranzistor+NPN+2n2222+TO-92&results=4) | 3 | Amplificare semnal (LED/Buzzer) |
| [Driver L293D](https://www.optimusdigital.ro/ro/drivere-de-motoare-cu-perii/13613-driver-de-motoare-l293d.html?search_query=Driver+de+Motoare+L293D&results=6) | 1 | Controlarea motoarelor fluturilor |
| LED-uri albe (+ rezistențe 470Ω) | 11 | Iluminare |
| LED-uri roșii (+ rezistențe 220Ω) | 11 | Iluminare |
| LED-uri galbene (+ rezistențe 220Ω) | 11 | Iluminare |
| Baterii 9V | 5 | Alimentare logică și motoare |
| Baterii 1.5V | 4 | Alimentarea motoarelor șasiului |
| **ELEMENTE DECORATIVE ȘI DE FIXARE** | | |
| Spumă EVA | - | Pentru realizarea fluturilor |
| Fetru | - | Pentru realizarea florilor |
| Zip ties | - | Pentru fixarea componentelor |
| Șuruburi și piulițe | - | Pentru fixarea componentelor |
| Sârmă | - | Elemente structurale |
| Discuri metalice (2.5cm) | 2 | Pentru excentric |
| Tije de lemn (~10cm) | 2 | Suport pentru motoarele fluturilor |

## Detalii tehnice și arhitectură

### Sursa de inspirație

Acest proiect este o adaptare bazată pe multiple resurse, combinând robotica cu elementele mecanice.</br>
* [Locomoție](https://www.instructables.com/DIY-Joystick-Controlled-Remote-Car-Using-Arduino/)</br>
* Fluturi [🦋](https://www.youtube.com/shorts/u5PJN3zsB4Q) [🦋](https://www.youtube.com/watch?v=BPetj9RztrI)</br>

### Ce aduce nou acest proiect?

Față de tutorialele standard acest proiect aduce:

1. **Sistem animatronic integrat**: Adăugarea a două mecanisme excentric-bielă acționate independent, care simulează zborul fluturilor.</br>
2. **Arhitectura multi-driver**: Coordonarea simultana a unui driver TB6612FNG (pentru tracțiune) și a unui driver L293D (pentru elementele decorative).</br>
3. **Design estetic functional**: Construcția manuală a elementelor mecanice.</br>

### Analiza sitemului

**Q1. Care este limita sistemului?**

Limita sistemului este definită de interfața fizică a celor două module:

* **Intrare (Input):** interacțiune fizică a utilizatorului cu joystick-ul
* **Iesire (Output):** mișcarea roților pe suprafața de rulare, mișcarea aripilor fluturilor și semnalele audio-vizuale
    
*Notă: Robotul funcționeaza în buclă deschisa (open-loop) pentru deplasare, fără senzori de evitare a obstacolelor.*

**Q2. Unde "locuiește" inteligența?**

Procesarea este distribuită între două noduri:

* **Transmițător:** Arduino Nano citește datele analogice, le procesează și le trimite prin pachete radio.
* **Receptor:** Arduino Nano decodează comenzile, calculează mixajul pentru direcția diferențială și gestionează PWM-ul pentru 6 motoare simultan.

**Q3. Care este cea mai dificilă problemă tehnică?**

Cea mai mare provocare a fost proiectarea mecanismului pentru mișcarea aripilor, trecând prin mai multe iterații de design pentru a rezolva probleme de mecanică fină.

1.  **Scripete:** Inițial, pentru a simula zborul fluturelui, am dorit suspendarea acestuia pe un scripete. Am abandonat ideea înainte de a începe implementarea din cauza riscului de încâlcire a firelor motorului și a oscilațiilor necontrolate cauzate de centrul de greutate variabil.
2.  **Bielă-manivelă în carcasă:** Am încercat un sistem bielă-manivelă cu motorul și axul într-o cutie. Din cauza realizării manuale a axului, au apărut erori de centrare: tija lovea pereții carcasei și bloca mecanismul. Deblocarea ar fi necesitat o logică software complexă (rotație inversă la detecția blocajului), ineficientă în practică. 

<table>
  <tr>
    <td width="50%"><a href="Montaje/carcasa_biela_manivela.jpeg"><img src="Montaje/carcasa_biela_manivela.jpeg" width="100%" alt="Carcasa biela-manivela"></a></td>
    <td width="50%"><a href="Montaje/schita_carcasa_biela_manivela.jpeg"><img src="Montaje/schita_carcasa_biela_manivela.jpeg" width="100%" alt="Schita carcasa biela-manivela"></a></td>
  </tr>
</table>

3.  **Soluția Finală (Excentric):** Am ales ideea de excentric-bielă fără carcasă restrictivă, care s-a dovedit a fi cea mai fiabilă și stabilă soluție, eliminând blocajele mecanice.

**Q4. Care este demo-ul minim funcțional?**

Sistemul trebuie să demonstreze:

* Conexiune radio stabilă.
* Controlul direcției (față/spate/stânga/dreapta) de la distanță.
* Activarea mecanismului de aripi la primirea comenzii specifice.

**Q5. De ce nu este doar un simplu tutorial?**

Proiectul necesită integrare de sisteme, nu doar replicare:

* Sincronizarea a două tipuri de drivere de motor.
* Proiectare mecanică pentru conversia mișcării (excentric-bielă).
* Managementul puterii pentru 3 nivele de tensiune (9V, 5V, 3.3V).

## 4. 📸 Galerie Foto & Video 🎥
### Scheme electrice:

<table>
  <tr>
    <td width="50%"><a href="SchemeElectrice/schema_sasiu_si_fluturi.jpg"><img src="SchemeElectrice/schema_sasiu_si_fluturi.jpg" width="100%" alt="Schema sasiu si fluturi"></a></td>
    <td width="50%"><a href="SchemeElectrice/schema_telecomanda.jpg"><img src="SchemeElectrice/schema_telecomanda.jpg" width="100%" alt="Telecomanda"></a></td>
  </tr>
</table>

### Montaje:

<table>
  <tr>
    <td width="25%"><a href="Montaje/suport_motoare.jpeg"><img src="Montaje/suport_motoare.jpeg" width="100%" alt="Suport"></a></td>
    <td width="25%"><a href="Montaje/excentric.jpeg"><img src="Montaje/excentric.jpeg" width="100%" alt="Excentric"></a></td>
    <td width="25%"><a href="Montaje/ansamblu_motor1.jpeg"><img src="Montaje/ansamblu_motor1.jpeg" width="100%" alt="Motor1"></a></td>
    <td width="25%"><a href="Montaje/ansamblu_motor2.jpeg"><img src="Montaje/ansamblu_motor2.jpeg" width="100%" alt="Motor2"></a></td>
  </tr>
  <tr>
    <td width="25%"><a href="Montaje/sasiu.jpeg"><img src="Montaje/sasiu.jpeg" width="100%" alt="Sasiu"></a></td>
    <td width="25%"><a href="Montaje/sasiu_si_driver_fluturi.jpeg"><img src="Montaje/sasiu_si_driver_fluturi.jpeg" width="100%" alt="Driver1"></a></td>
    <td width="25%"><a href="Montaje/sasiu_si_driver_fluturi2.jpeg"><img src="Montaje/sasiu_si_driver_fluturi2.jpeg" width="100%" alt="Driver2"></a></td>
    <td width="25%"><a href="Montaje/sasiu_si_fluturi.jpeg"><img src="Montaje/sasiu_si_fluturi.jpeg" width="100%" alt="Ansamblu"></a></td>
  </tr>
  <tr>
    <td width="25%"><a href="Montaje/fluture_mare.jpeg"><img src="Montaje/fluture_mare.jpeg" width="100%" alt="Fluture mare"></a></td>
    <td width="25%"><a href="Montaje/fluture_mic.jpeg"><img src="Montaje/fluture_mic.jpeg" width="100%" alt="Fluture mic"></a></td>
    <td width="25%"><a href="Montaje/telecomanda1.jpeg"><img src="Montaje/telecomanda1.jpeg" width="100%" alt="Sasiu"></a></td>
    <td width="25%"><a href="Montaje/telecomanda2.jpeg"><img src="Montaje/telecomanda2.jpeg" width="100%" alt="Sasiu"></a></td>
</table>