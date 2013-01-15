#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import sys
import imp
from xml.dom import minidom

class PluginManager(object):
	"""
	"""
	version_ = "1.0"
	def __init__(self):
		"""
		"""
		self.modules_ = {}

	def load(self, key, filename):
		"""
		
        Arguments:
        - `self`:
        - `key_name`:
		- `filename`:
        """
		try:
			module = imp.load_dynamic(key, filename)
			qtclass = getattr(module, key)

			# 调用模块的注册函数，如果成功则将模块添加到模块列表中
			# 如果存在两个同名的模块，会出现问题
			if qtclass.registerToSystem(PluginManager.version_):
				self.modules_[key] = qtclass()
		except Exception as e:
			print("Error:", e)

	def loadFromXML(self, filename):
		"""
		
        Arguments:
        - `self`:
        - `filename`:
        """
		doc = minidom.parse(filename)
		root = doc.documentElement
		modules = root.getElementsByTagName('module')

		for module in modules:
			names = module.getElementsByTagName('name')
			key = names[0].childNodes[0].nodeValue

			locations = module.getElementsByTagName('location')
			filename = locations[0].childNodes[0].nodeValue

			self.load(key, filename)
			
	def loadAll(self, dir):
		"""
		
        Arguments:
        - `self`:
        - `path`:
        """

		files_list = os.listdir(dir)
		for line in files_list:
			file_path = os.path.join(dir, line)
			if os.path.isdir(file_path):
				continue
			file_info = os.path.splitext(os.path.basename(file_path))
			if file_path.endswith(".so"):
				self.load(file_info[0], file_path)
        
	def unload(self, key):
		"""
		
        Arguments:
        - `self`:
        - `key`:
        """
		if self.modules_.get(key):
			del modules_[key]
			
	def modules(self):
		"""
		
        Arguments:
        - `self`:
        """
		return self.modules_.keys()
