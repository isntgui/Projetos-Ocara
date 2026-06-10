const serverIP = "http://100.64.2.70"; // Troque pelo IP do seu ESP8266

let ledOn = false;

// Função para obter os dados do ESP8266
function getData() {
    fetch(`${serverIP}/get`) // Requisição para o endpoint /get do seu ESP8266
        .then((response) => response.json())
        .then((data) => {
            // Atualizando os elementos HTML com os dados recebidos
            document.getElementById("temp").textContent =
                data.temperatura.toFixed(1);
            document.getElementById("hum").textContent =
                data.umidade.toFixed(1);
            ledOn = data.led === 1; // Atualizando o estado do LED
            updateButton(); // Atualizando o botão do LED
        })
        .catch((error) => {
            console.log("Erro:", error); // Se ocorrer algum erro na requisição
        });
}

// Função para alternar o estado do LED
function toggleLED() {
    ledOn = !ledOn;
    fetch(`${serverIP}/led?valor=${ledOn ? "1" : "0"}`) // Envia a requisição para alterar o LED
        .then(() => updateButton())
        .catch((error) => console.log("Erro ao alterar LED:", error));
}

// Função para atualizar o texto e o estilo do botão do LED
function updateButton() {
    const btn = document.getElementById("ledBtn");
    btn.textContent = ledOn ? "Desligar" : "Ligar";
    btn.className = ledOn ? "off" : "";
}

// Chamando a função getData a cada 3 segundos para atualizar os dados
setInterval(getData, 3000);

// Chamando a função getData quando a página for carregada
window.onload = getData;
