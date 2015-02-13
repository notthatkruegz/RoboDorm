import web
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
render = web.template.render('templates/')
urls = ('/', 'index')
floorLamp = False
deskLampZ = False
deskLampB = False
bedLamp = False

class index:
	def GET(self):
		global floorLamp
		global deskLampZ
		global deskLampB
		global bedLamp
		
		data = web.input(c = None)
		
		# Floor Lamp
		if data.c == "floorLamp" and floorLamp:
			ser.write("floorLampOff")
			floorLamp = False
		elif data.c == "floorLamp" and not floorLamp:
			ser.write("floorLampOn")
			floorLamp = True
		# Zach Desk Lamp
		elif data.c == "deskLampZ" and deskLampZ:
			ser.write("deskLampZOff")
			deskLampZ = False
		elif data.c == "deskLampZ" and not deskLampZ:
			ser.write("deskLampZOn")
			deskLampZ = True
		# Bridger Desk Lamp
		elif data.c == "deskLampB" and deskLampB:
			ser.write("deskLampBOff")
			deskLampB = False
		elif data.c == "deskLampB" and not deskLampB:
			ser.write("deskLampBOn")
			deskLampB = True
		# Zach Bed Lamp
		elif data.c == "bedLamp" and bedLamp:
			ser.write("bedLampOff")
			bedLamp = False
		elif data.c == "bedLamp" and not bedLamp:
			ser.write("bedLampOn")
			bedLamp = True
		return render.index(data.c, floorLamp, deskLampZ, deskLampB, bedLamp)

if __name__ == "__main__":
	app = web.application(urls, globals())
	app.run()
