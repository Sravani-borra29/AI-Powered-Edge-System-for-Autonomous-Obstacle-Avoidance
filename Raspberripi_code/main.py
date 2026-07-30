# 1. Hardware Pin Setup

GPIO.setmode(GPIO.BCM)

GPIO.setup([18, 23, 24, 13, 27, 22, 17], GPIO.OUT)

pwmA = GPIO.PWM(18, 1000) # PWM for Left Motors

pwmB = GPIO.PWM(13, 1000) # PWM for Right Motors

pwmA.start(0); pwmB.start(0); GPIO.output(17, True)

# 2. Flask and Serial Initialization

app = Flask(__name__)
socketio = SocketIO(app)
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)

# 3. AI Capture Function

def analyze_object():

    cam = cv2.VideoCapture(0)

    ret, frame = cam.read()

    if ret:

        # Encode for API

        _, buffer = cv2.imencode('.jpg', frame)

        img_str = base64.b64encode(buffer).decode('utf-8')

        # OpenAI API Transaction

        # (API Key and Request Logic would go here)

        socketio.emit('ai_result', {'message': 'Analyzing...'})

    cam.release()

# 4. Main Control Loop (Simplified)

def robot_loop():

    while True:

        if ser.in_waiting > 0:

            data = ser.readline().decode('utf-8').strip().split(',')

            if len(data) == 3:

                L, C, R = map(int, data)

                # Obstacle Detection Logic

                if C < 40:

                    analyze_object()  # Trigger AI

                socketio.emit('sensor_data', {'l': L, 'c': C, 'r': R})

        time.sleep(0.05)

# Start Threads

threading.Thread(target=robot_loop, daemon=True).start()

if __name__ == '__main__':

    socketio.run(app, host='0.0.0.0', port=5000)