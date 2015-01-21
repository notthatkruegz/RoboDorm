import web
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

render = web.template.render('templates/')

urls = (
	'/', 'index'
)

floorLamp = False
deskLamp = False
bedLamp = False

class index:
	def GET(self):
		global floorLamp
		global deskLamp
		global bedLamp

		data = web.input(c=None)

		if data.c == "floorLamp" and floorLamp:
			ser.write("floorLampOff")
			floorLamp = False;
		elif data.c == "floorLamp" and not floorLamp:
			ser.write("floorLampOn")
			floorLamp = True;
		elif data.c == "deskLamp" and deskLamp:
			ser.write("deskLampOff")
			deskLamp = False;
		elif data.c == "deskLamp" and not deskLamp:
			ser.write("deskLampOn")
			deskLamp = True;
		elif data.c == "bedLamp" and bedLamp:
			ser.write("bedLampOn")
			bedLamp = False;
		elif data.c == "bedLamp" and not bedLamp:
			ser.write("bedLampOff")
			bedLamp = True;

		return render.index(data.c, floorLamp, deskLamp, bedLamp)

if __name__ == "__main__":
	app = web.application(urls, globals())
	app.run()