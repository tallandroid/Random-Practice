try:
    import gtk
    import math
except:
    SystemExit
   
class TestBubble(gtk.DrawingArea):
    def __init__(self):
        gtk.DrawingArea.__init__(self)
        self.connect("expose_event",self.expose)
       
    def expose(self,widget,event):
        self.context = widget.window.cairo_create()
        #self.draw_layout(self.context,25,25,self.create_pango_layout("text"))
        self.context.rectangle(event.area.x,event.area.y,
                               event.area.width,event.area.height)
        self.context.clip()
        self.draw(self.context)
        return False
   
    def draw(self,context):
        rect = self.get_allocation()
        width = 9*rect.width/10
        height = 2*rect.height/3
        x = rect.x+rect.width/10
        y = rect.y+rect.height/10
        radius = min(rect.height,rect.width)/10
       
        context.arc(x,y,radius,math.pi,3*math.pi/2)
        context.arc(x+width-radius,y,radius,(-1)*math.pi/2,0)
        context.arc(x+width-radius,y+height-radius,radius,0,math.pi/2)
        context.rel_line_to((-1)*width/2,0)
        context.rel_line_to((-1)*width/3,height/4)
        context.rel_line_to(width/5,(-1)*rect.height/6)
        context.arc(x,y+height-radius,radius,math.pi/2,math.pi)
        context.close_path()
       
        context.set_source_rgb(1,1,1)
        context.fill_preserve()
        context.set_source_rgb(0,0,0)
        context.set_line_width(0.4)
        context.stroke()
   
   
def main():
	window = gtk.Window()
	bubble = TestBubble()
    
	fixed = gtk.Fixed()
	window.add(fixed)
	fixed.show()

	event_box_bubble = gtk.EventBox()
	fixed.put(event_box_bubble,20,20)
	event_box_bubble.show()
	
	
	"""event_box = gtk.EventBox()
	fixed.put(event_box,50,20)    
	event_box.show()
	
	label = gtk.Label("zzz")
	event_box.add(label)
	label.show()"""

	event_box_bubble.add(bubble)
	bubble.show()
	window.connect("destroy",gtk.main_quit)
	window.show_all()
	gtk.main()
   
 
if __name__=="__main__":
    main()
