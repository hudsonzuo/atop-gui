#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui, QtCore

sys.path.append("core")
sys.path.append("mainwindow")
import plugin_manager
import mainwindow

def main():
	"""
	"""
	app = QtGui.QApplication(sys.argv)

	w = mainwindow.MainWindow()
	
	pm = plugin_manager.PluginManager()
	#	pm.loadFromXML('config.xml')
	pm.loadAll("components/curveanalyzer")
	print pm.modules()

	for m in pm.modules_:
		instance = pm.modules_.get(m)
		w.addTab(m, instance)
	
	w.showMaximized()
	
	sys.exit(app.exec_())
	
if __name__ == "__main__":
	main()
