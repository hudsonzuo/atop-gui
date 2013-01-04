#!/usr/bin/python3
# -*- encoding:utf-8 -*-

import subprocess
from  time import sleep
from gi.repository import Gtk,GObject,Pango
from multiprocessing import Process

class atop(Gtk.Window):
   def __init__(self):
      Gtk.Window.__init__(self,title="Graphical atop")
      self.set_border_width(10)
      self.set_default_size(600,200)
      self.vb_main=Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
      self.add(self.vb_main)
      self.t_v = Gtk.TextView()
      self.t_v.set_editable(False)
      fontdesc = Pango.FontDescription("文泉驿等宽正黑 12")
      self.t_v.modify_font(fontdesc)
      self.t_b = self.t_v.get_buffer()
      self.timeout_id = GObject.timeout_add(5000, self.updater, None)
      self.vb_main.pack_start(self.t_v,True,True,0)
   def updater(self,userdata):   
      pg=subprocess.getstatusoutput("atop 1 1")
      #print(pg[1])
      self.t_b.set_text(pg[1])
      return True
win=atop()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()

     # p1 = Popen(["atop"], stdout=PIPE)
     # p2 = Popen(["cat"], stdin=p1.stdout)
