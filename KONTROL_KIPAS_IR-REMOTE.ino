//KONTROL KECEPATAN KIPAS MENGGUNAKAN IR REMOT

#include<IRremote.h> //library ir remote

//Inisialisasi PIN yang digunakan
int cepat = 2; //kecepatan kipas cepat, prototipe menggunakan led atau relay
int sedang = 3; // kecepatan kipas sedang, prototipe menggunakan led atau relay
int lambat = 4; //kecepatan kipas lambat, prototipe menggunakan led atau relay
int mati = 5; //kipas mati, semua led atau relay mati
const int pinIR = 11; //Pin IR

IRrecv recv(pinIR); //Deklarasi pin IR
decode_results hasil; // variabel untuk menampung data dari remot

void setup() {
  Serial.begin(9600);
  recv.enableIRIn(); //perintah untuk IR receiver membaca data
  
  //DEKLARASI PIN SEBAGAI OUTPUT
  pinMode(cepat, OUTPUT);
  pinMode(sedang, OUTPUT);
  pinMode(lambat, OUTPUT);
  pinMode(mati, OUTPUT);
}

void loop() {
  //MEMBACA DATA YANG DITERIMA OLEH IR RECEIVER
  if (recv.decode(&hasil)) {
    Serial.println(hasil.value);

    //PERINTAH UTUK MEMATIKAN KIPAS
    if (hasil.value == 16738455) {
      digitalWrite(cepat, LOW);
      digitalWrite(sedang, LOW);
      digitalWrite(lambat, LOW);
      Serial.println("KIPAS MATI");
    }

    //PERINTAH UNTUK PUTARAN CEPAT KIPAS
    if (hasil.value == 16724175) {
      digitalWrite(cepat, HIGH);
      digitalWrite(sedang, LOW);
      digitalWrite(lambat, LOW);
      Serial.println("KIPAS PUTAR CEPAT");
    }

    //PERINTAH UNTUK PUTARAN SEDANG KIPAS
    if (hasil.value == 16718055) {
      digitalWrite(sedang, HIGH);
      digitalWrite(cepat, LOW);
      digitalWrite(lambat, LOW);
      Serial.println("KIPAS PUTAR SEDANG");
    }

    //PERINTAH UNTUK PUTARAN LAMBAT KIPAS
    if (hasil.value == 16743045) {
      digitalWrite(lambat, HIGH);
      digitalWrite(cepat, LOW);
      digitalWrite(sedang, LOW);
      Serial.println("KIPAS PUTAR LAMBAT");
    }
    recv.resume(); // Melanjutkan pembacaan data
  }
}
