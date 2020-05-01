/*==============================================================================
   BIBLIIOTECAS OBRIGATÓRIAS
  ============================================================================*/
#include <SPI.h>//Estabelece a comunicação com via protocolo SPI no Arduino.
#include <Ethernet.h>//Configura o conjunto (arduino + shield ) como rede local.
/*==============================================================================
   INFORMAÇÕES SOBRE ENDEREÇAMENTO DE IP
  ============================================================================*/
String readString;//Armazena em uma 'string'os caracteres do bufer serial.
byte mac[] = {0xA4, 0x28, 0x72, 0xCA, 0x55, 0x2F};//Endereço físico associado ao conjunto (arduino + shield) na rede.

/*
  ATENÇÃO! O endereço IP precisa ser único, para que haja conexão entre
  o conjunto e a rede local.
  última atualização 01/04/2020
*/

byte ip[] = {192, 168, 0, 110};

EthernetServer server(80);//Cria um 'objeto' responsável por representar o servidor web usando a porta padrão 80.


/*==============================================================================
   SETUP()
  ============================================================================*/
void setup() {
  Serial.begin(9600);//Inicializa o serial monitor.
  Ethernet.begin(mac, ip);//Inicializa a conexão com a rede local, utilizando o endereço IP E MAC.
  server.begin(); //Inicializa o servidor da web.
}//end void setup


/*==============================================================================
   LOOP()
  ============================================================================*/
void loop() {
  //Objeto Server avalia se há dados disponíveis para leitura armazena na função 'EthernetClient cliente'.
  EthernetClient client = server.available();

  //Se existir tentativa de conexão do cliente com o  servidor através do endereço IP pré-configurado, as instruções abaixo serão executadas.
  if (client) {
    //Condição utilizado para forçar o programa ficar restito apenas as informações do seu conteúdo, através do parâmetro client.connected().
    while (client.connected()) {

      /*==============================================================================
        IMPLEMENTAÇÃO DE HTML NO CÓIGO
        ============================================================================*/
      client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head>");
      client.println("<!-- Meta tags Obrigatórias -->");
      client.println("<meta charset='utf-8'>");
      client.println("<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>");
      client.println("<title>Titulo da Página</title>");
      client.println("</head>");
      client.println("<body bgcolor='#F0FFFF'>");
      client.println("<h1 style='color: #FF4500; text-align: center;'>Olá, mundo!</h1>");
      client.println("<div align='center'>");
      client.println("<object width='425' height='344' data='https://www.youtube.com/embed/F9Bo89m2f6g'></object>");
      client.println("<hr width='30%' size='5' noshade >");
      client.println("</div>");
      client.println("<p>Parabéns <b>ALUNO :) </b></p>");
      client.println("<p>Agora é com você. Eu sugiro que a partir de agora você mesmo faça pequenas <b>ALTERAÇÕES</b> no seu texto. Procure colocar fotos, trocar fontes, cores de texto, insira links, em fim, aproveite a aportunidade de colocar em pratica, todos os seus conhecimentos de HTML em prática. </p>");
      client.println("<p>Então é com<b>VOCÊ!</b>.<br> Não esqueça que tendo qualquer dúvida você pode entrar em contato, se precisar.</p>");
      client.println("</body>");
      client.println("</html>");
      delay(1);// Delay() para garantir que o navegador receba esta informação que estamos enviado.
      client.stop();// Condição encerrar a conexão.

    }//Condição utilizado para forçar o programa ficar restito apenas as informações do seu conteúdo, através do parâmetro client.connected().
  }//Se existir tentativa de conexão do cliente com o  servidor através do endereço IP pré-configurado, as instruções abaixo serão executadas.
}//end void loop
