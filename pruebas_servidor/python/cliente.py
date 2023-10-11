import http.client

# Definir los datos de inicio de sesión
username = "pepe"
password = "123456"

# Definir la dirección IP y el puerto del servidor
ip = "192.168.0.22"
port = 3333

# Definir llos encabezados HTTP
headers = {'Content-type': 'application/x-www-form-urlencoded'}

# Definir los datos que se enviarán al servidor
data = 'username=' + username + '&password=' + password

# Crear una conexión HTTP con el servidor
conn = http.client.HTTPSConnection(ip, port)

# Enviar los datos de inicio de sesión a través de HTTP
conn.request("POST", "/login", body=data, headers=headers)

# Obtener la respuesta del servidor
response = conn.getresponse()

# Verificar si la solicitud se ha completado correctamente
if response.status == 200:
    print("Inicio de sesión exitoso!")
else:
    print("Error en el inicio de sesión:", response.reason)

# Cerrar la conexión HTTP
conn.close()
