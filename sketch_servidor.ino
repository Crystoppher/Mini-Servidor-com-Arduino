//=============================================================================================================
/* Bibliotecas obrigatórias */
//=============================================================================================================
#include <SPI.h>//Estabelece a comunicação com via protocolo SPI no Arduino.
#include <Ethernet.h>//Configura o conjunto (arduino + shield ) como rede local.

//=============================================================================================================
/* Informacoes de endereco IP */
//=============================================================================================================
String readString;// Lê caracteres do buffer serial e os move para uma String.
byte mac[] = {0xA4, 0x28, 0x72, 0xCA, 0x55, 0x2F}; //Endereço físico associado ao conjunto (arduino + shield) na rede.
byte ip[] = {192, 168, 0, 110}; //ENDEREÇO DE IP OBRIGATÓRIO para que haja conexão entre o conjunto e a rede local.

EthernetServer server(80); //Cria um 'objeto' responsável por representar o servidor web.
//Por padrão utiliza-se a porta 80 'padrão' para endereço HTTP.

void setup() {
  Serial.begin(9600);//Inicializa o serial monitor.
  Ethernet.begin(mac, ip);//Inicializa a conexão com a rede local.
  server.begin(); //Inicializa o servidor da web.
}//end void setup


void loop() {
  EthernetClient client = server.available();//Objeto Server avalia se há dados disponíveis para leitura e
  //armazena na função 'EthernetClient cliente'.

  //Objeto Server será avaliado como falso no laço de repetição IF.
  if (client) {//Se existir tentativa de conexão do cliente com o  servidor através do endereço IP
    //pré-configurado, as instruções abaixo serão executadas.

    while (client.connected()) { //Condição utilizado para forçar o programa ficar restito apenas as
      //informações do seu conteúdo, através do parâmetro client.connected().

      //=============================================================================================================
      /* TRECHO DE CÓDIGO ABAIXO LIBERADO PARA ALTERAÇÃO!*/
      //=============================================================================================================
      client.println("<!DOCTYPE html>");
      client.println("<html>");

      client.println("<head>");
      client.println("<!-- Meta tags Obrigatórias -->");
      client.println("<meta charset='utf-8'>");
      client.println("<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>");
      client.println("<title>Pagina Inicial</title>");
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
