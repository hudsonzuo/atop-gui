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
		self.tabwidget_ = QtGui.QTabWidget()		
		self.layout().addWidget(self.tabwidget_)
		
	def addTab(self, name, module):
		"""
		
		Arguments:
		- `module`:
		"""
		self.tabwidget_.addTab(module, name)

	def resizeEvent(self, event=None):
		"""
		
		Arguments:
		- `QResizeEvent`:
		"""
		self.tabwidget_.resize(self.size())
		
