import cv2
import numpy as np
from twilio.rest import Client

# Inicialize o detector de rostos utilizando o classificador CascadeClassifier
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Adicione suas informações de conta Twilio aqui
account_sid = "ACa6d1e528f9fead11ac12304247cd0f7d"
auth_token = "212d1e1d4e4efd0df29b04490abc0ed2"

def send_whatsapp_message(num_faces):
    client = Client(account_sid, auth_token)

    message = client.messages.create(
        to="whatsapp:+5589994244460",  # Número de telefone destino
        from_="whatsapp:+16067812765",  # Número de telefone Twilio
        body="Foram detectadas {} pessoas em sua câmera de segurança".format(num_faces)
    )

    print("Mensagem enviada: {}".format(message.sid))

# Carrega o classificador de rostos
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Nome do arquivo de vídeo
filename = 'video.mp4'

# Abre o vídeo
cap = cv2.VideoCapture(filename)

while True:
    ret, frame = cap.read()

    if ret:
        # Converte a imagem para escala de cinza
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Detecta os rostos na imagem
        faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

        # Desenha um retângulo ao redor de cada rosto detectado
        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)

        # Mostra a imagem com os rostos destacados
        cv2.imshow('video', frame)

        # Verifica se a tecla 'q' foi pressionada
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break

        # Verifica se houve algum rosto detectado
        if len(faces) > 0:
            # Envia uma mensagem pelo Twilio informando o número de rostos detectados
            send_whatsapp_message(len(faces))

            # Pausa o loop de captura de vídeo
            break

    else:
        # Pausa o loop de captura de vídeo
        break

# Libera os recursos da câmera e fecha a janela do OpenCV
cap.release()
cv2.destroyAllWindows()