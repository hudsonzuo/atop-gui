#!/usr/bin/python2
# -*- coding: utf-8 -*-

from PyQt4 import QtGui, QtCore

class MainWindow(QtGui.QMainWindow):
	"""
	"""
	
	def __init__(self):
		"""
		"""
		super(QtGui.QMainWindow, self).__init__()
		self.tabWidget_ = QtGui.QTabWidget(self)

	def addPage(self, module, name):
		"""
		
		Arguments:
		- `module`:
		- `name`:
		"""
		self.tabWidget_.addTab(module, name)
		
	def resizeEvent(self, event=None):
		"""
		
		Arguments:
		- `event`:
		"""
		self.tabWidget_.resize(self.size())
		
