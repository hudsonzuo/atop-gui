#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui, QtCore

sys.path.append("core")
import plugin_manager

class MainWindow(QtGui.QWidget):
    """
    """
	
    def __init__(self):
        """
        """
        super(MainWindow, self).__init__()


def main():
	"""
	"""
	app = QtGui.QApplication(sys.argv)

	w = MainWindow()
	
	pm = plugin_manager.PluginManager()
	pm.loadFromXML('config.xml')

	w.show()
	
	sys.exit(app.exec_())
	
if __name__ == "__main__":
	main()
