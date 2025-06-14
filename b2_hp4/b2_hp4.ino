#include <WiFi.h>
#include <DHT.h>

// --- WiFi Settings ---
const char* ssid = "TEKY OFFICE_2G";
const char* password = "Teky@2018";

// --- Server Settings ---
const char* serverIp = "192.168.1.223"; // Thay bằng IP máy bạn
const uint16_t serverPort = 8080;          // Port Netcat lắng nghe

// --- DHT Settings ---
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// --- WiFi Client Object ---
WiFiClient client;
int data = 0;

void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();

  // --- Connect to WiFi ---
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 20) {
      Serial.println("\nFailed to connect WiFi!");
      return;
    }
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
  data++;
  Serial.print("Connecting to server ");
  Serial.print(serverIp); 
  Serial.print(":"); 
  Serial.println(serverPort);

  // Thử kết nối đến server
  if (client.connect(serverIp, serverPort)) {
    Serial.println("Connected to server!");

    // Đọc cảm biến DHT
    // float h = dht.readHumidity();
    // float t = dht.readTemperature();
    float h = data*2;
    float t = data + 2;
    String dataString = "Temp: " + String(t, 1) + " C, Humid: " + String(h, 1) + " %";

    // Gửi dữ liệu đến server
    client.println(dataString);
    Serial.print("Sent: ");
    Serial.println(dataString);

    // Đóng kết nối
    client.stop();
    // Serial.println("Connection closed.");
    // Kiểm tra lỗi đọc DHT
    // if (isnan(h) || isnan(t)) {
    //   Serial.println("Failed to read from DHT sensor!");
    //   client.stop(); // Đóng kết nối nếu đọc lỗi
    // } else {
    //   // Tạo chuỗi dữ liệu
    //   String dataString = "Temp: " + String(t, 1) + " C, Humid: " + String(h, 1) + " %";

    //   // Gửi dữ liệu đến server
    //   client.println(dataString);
    //   Serial.print("Sent: ");
    //   Serial.println(dataString);

    //   // Đóng kết nối
    //   client.stop();
    //   Serial.println("Connection closed.");
    // }
  } else {
    Serial.println("Connection failed!");
  }

  // Chờ 5 giây trước khi thử gửi lại
  delay(5000);
}
