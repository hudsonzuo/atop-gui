#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import sipconfig
from PyQt4 import pyqtconfig

build_file = "curveanalyzer.sbf"

config = pyqtconfig.Configuration()

pyqt_sip_flags = config.pyqt_sip_flags

os.system(" ".join([config.sip_bin, "-c", ".", "-b", build_file, "-I", config.pyqt_sip_dir, pyqt_sip_flags, "curveanalyzer.sip"]))

installs = []

installs.append(["curveanalyzer.sip", os.path.join(config.default_sip_dir, "curveanalyzer")])

makefile = pyqtconfig.QtGuiModuleMakefile(
	configuration=config,
	build_file=build_file,
	installs=installs
)

makefile.extra_libs = ["CurveAnalyzer"]
makefile.extra_lib_dirs = ["pureqt"]
makefile.extra_include_dirs = ["pureqt"]
makefile.LIBDIR.append("./lib")

makefile.generate()
os.
