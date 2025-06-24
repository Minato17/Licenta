import cv2
import numpy as np
import time

last_print_color = 0
delay = 10 


cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)

if not cap.isOpened():
    print("Eroare: Camera nu a putut fi deschisa.")
    exit()

while True:
    ret, frame = cap.read()
    if not ret:
        print("Eroare: Nu se poate citi cadrul de la camera.")
        break
    detected = False
    current_time = time.time()
    
    # Conversia imaginii din BGR in HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Definirea intervalelor HSV pentru culorile rosu, verde si albastru
    #Definirea intervalului pentru culoarea rosu  HSV
    lower_red1 = np.array([0, 120, 70])
    upper_red1 = np.array([10, 255, 255])
    lower_red2 = np.array([170, 120, 70])
    upper_red2 = np.array([180, 255, 255])

    # Definirea intervalului pentru culoarea verde  HSV
    lower_green = np.array([40, 70, 70])
    upper_green = np.array([80, 255, 255])
    
    # Definirea intervalului pentru culoarea albastru  HSV
    lower_blue = np.array([94, 80, 2])
    upper_blue = np.array([126, 255, 255])

    # Crearea mastilor pentru fiecare culoare
    mask_red1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask_red2 = cv2.inRange(hsv, lower_red2, upper_red2)
    mask_red = cv2.bitwise_or(mask_red1, mask_red2)

    mask_green = cv2.inRange(hsv, lower_green, upper_green)
    mask_blue = cv2.inRange(hsv, lower_blue, upper_blue)

    # Aplicarea operatiilor morfologice pentru a elimina zgomotul
    kernel = np.ones((5, 5), np.uint8)
    mask_red = cv2.morphologyEx(mask_red, cv2.MORPH_OPEN, kernel)
    mask_green = cv2.morphologyEx(mask_green, cv2.MORPH_OPEN, kernel)
    mask_green = cv2.morphologyEx(mask_green, cv2.MORPH_CLOSE, kernel)
    mask_blue = cv2.morphologyEx(mask_blue, cv2.MORPH_OPEN, kernel)

    # Detectarea contururilor si desenarea dreptunghiurilor
    contours_red, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours_green, _ = cv2.findContours(mask_green, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours_blue, _ = cv2.findContours(mask_blue, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours_red:
        area = cv2.contourArea(cnt)
        if area > 500:
            x, y, w, h = cv2.boundingRect(cnt)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
            cv2.putText(frame, "Rosu", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 0, 255), 2)
            if current_time - last_print_color > delay:
                print("Rosu detectat!")
                last_print_color = current_time
        break 
         
    
    for cnt in contours_green:
        area = cv2.contourArea(cnt)
        if area > 500:
            x, y, w, h = cv2.boundingRect(cnt)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            cv2.putText(frame, "Verde", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
            if current_time - last_print_color > delay:
                print("Verde detectat!")
                last_print_color = current_time
        break
       

    for cnt in contours_blue:
        area = cv2.contourArea(cnt)
        if area > 500:
            x, y, w, h = cv2.boundingRect(cnt)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
            cv2.putText(frame, "Albastru", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 0), 2)
            if current_time - last_print_color > delay:
                print("Albastru detectat!")
                last_print_color = current_time
        break
     
    # Afisarea rezultatului
    cv2.imshow('Detectie Culori', frame)
    # Iesirea din bucla la apasarea tastei 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Eliberarea resurselor
cap.release()
cv2.destroyAllWindows()
