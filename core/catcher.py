#!/usr/bin/python3
#-*- encoding:utf-8 -*-
from subprocess import getstatusoutput
import sys
class catcher():
   def __init__(self):
      self.D_CPU=[]
         # 0total number of clock-ticks per second for this machine
         # 1number of processors
         # 2consumption  for  all  CPUs  in system mode (clock-ticks)
         # 3consumption for all CPUs in user mode (clock-ticks)
         # 4consumption   for all CPUs in user mode for niced processes (clock-ticks)
         # 5consumption for all CPUs  in  idle  mode  (clock-ticks)
         # 6consumption  for  all  CPUs  in wait mode (clock-ticks)
         # 7consumption for all CPUs in irq mode (clock-ticks)
         # 8consumption for all CPUs in softirq mode (clock-ticks)
         # 9consumption for all CPUs in steal mode (clock-ticks)
         # 10consumption  for all CPUs in guest mode (clock-ticks)
         # 11frequency of all CPUs 
         # 12frequency percentage of all CPUs.


      self.D_cpu=[]
         # 0total number of clock-ticks per second for this machine
         # 1processor-number
         # 2consumption  for this  CPU  in  system mode (clock-ticks)
         # 3consumption for this CPU in user mode (clock-ticks)
         # 4consumption for  this CPU in user mode for niced processes (clock-ticks)
         # 5consumption for this CPU in idle mode  (clock-ticks)
         # 6consumption  for this CPU in wait mode (clock-ticks)
         # 7consumption for this CPU in irq mode (clock-ticks)
         # 8consumption for this CPU in softirq mode (clock-ticks)
         # 9consumption for this CPU  in  steal  mode  (clock-ticks)
         # 10consumption  for  this CPU in guest mode (clock-ticks)
         # 11frequency of this CPU 
         # 12frequency percentage of this CPU.

      self.D_CPL=[]
         # 0number of processors
         # 1load average for last minute
         # 2load average  for  last  five  minutes
         # 3load average for last fifteen minutes
         # 4number of context-switches
         # 5number of device interrupts.

      self.D_MEM=[]
         # 0page size for this machine (in bytes)
         # 1size of physical memory (pages)
         # 2size of free memory(pages)
         # 3size of page cache (pages)
         # 4size of buffer cache (pages)
         # 5size of slab (pages)
         # 6dirty pages in  cache(pages)
         # 7reclaimable part of slab (pages).

      self.D_SWP=[]
         # 0page size for this machine (in bytes)
         # 1size of swap (pages)
         # 2size of free swap (pages)
         # 30(future use)
         # 4size of committed space (pages)
         # 5limit for committed space (pages).


      self.D_PAG=[]
         # 0page size for this machine (in bytes)
         # 1number of  page  scans
         # 2number  of  allocstalls
         # 30(future use)
         # 4number of swapins
         # 5number of swapouts.

      self.D_LVM=[]
         # 0name
         # 1number  of  milliseconds  spent for I/O
         # 2number of reads issued
         # 3number of sectors
         # 4transferred for reads
         # 5number of writes issued
         # 6number of sectors transferred for write.
      self.D_MDD=[]
         # 0name
         # 1number  of  milliseconds  spent for I/O
         # 2number of reads issued
         # 3number of sectors
         # 4transferred for reads
         # 5number of writes issued
         # 6number of sectors transferred for write.
      self.D_DSK=[]
         # 0name
         # 1number  of  milliseconds  spent for I/O
         # 2number of reads issued
         # 3number of sectors
         # 4transferred for reads
         # 5number of writes issued
         # 6number of sectors transferred for write.

      self.D_NET=[]
         # 0the verb "upper"
         # 1number of packets received by TCP
         # 2number of packets transmitted by  TCP
         # 3number  of  packets  received  by UDP
         # 4number of packets transmitted by UDP
         # 5number of packets received by IP
         # 6number of packets transmitted by IP
         # 7number of packets delivered to higher layers by IP
         # 8number of packets forwarded by IP.

         # Next one line is shown for every interface.

         # 0name  of  the  interface
         # 1number  of  packets received by the interface
         # 2number of bytes received by the interface
         # 3number of packets transmitted by the interface
         # 4number of bytes transmitted by  the  interface
         # 5interface speed
         # 6duplex mode (0=half 1=full).

      self.D_PRG=[]
         # 0PID  (unique ID of task)
         # 1name (between brackets)
         # 2state
         # 3real uid
         # 4real gid
         # 5TGID (group  number of related tasks/threads)
         # 6total number of threads
         # 7exit code
         # 8start time (epoch)
         # 9full  command  line (between  brackets)
         # 10PPID
         # 11number of threads in state 'running' (R)
         # 12number of threads in state 'interruptible sleeping' (S)
         # 13number of threads in state 'uninterruptible sleeping' (D)
         # 14effective uid
         # 15effective gid
         # 16saved uid
         # 17saved gid
         # 18filesystem uid
         # 19filesystem gid
         # 20elapsed time (hertz) 
         # 21is_process (y/n).

      self.D_PRC=[]
         # 0PID
         # 1name  (between  brackets)
         # 2state
         # 3total number of clock-ticks per second for this  machine
         # 4CPU-consumption in user mode (clockticks)
         # 5CPU-consumption in system mode (clockticks)
         # 6nice  value
         # 7priority
         # 8realtime  priority
         # 9scheduling  policy
         # 10current CPU
         # 11sleep average
         # 12TGID (group number of related  tasks/threads) 
         # 13is_process (y/n).

      self.D_PRM=[]
         # 0PID
         # 1name (between brackets)
         # 2state
         # 3page size for this machine (in bytes)
         # 4virtual  memory  size  (Kbytes)
         # 5resident  memory  size  (Kbytes)
         # 6shared  text  memory  size (Kbytes)
         # 7virtual memory growth (Kbytes)
         # 8resident memory growth (Kbytes)
         # 9number of minor page faults
         # 10number of major page  faults
         # 11virtual  library exec size (Kbytes)
         # 12virtual data size (Kbytes)
         # 13virtual stack size (Kbytes)
         # 14swap space used (Kbytes)
         # 15TGID (group number of related tasks/threads) 
         # 16is_process (y/n).

      self.D_PRD=[]
         # 0PID
         # 1name (between brackets)
         # 2state
         # 3obsoleted kernel patch installed  ('n')
         # 4standard  io statistics  used ('y' or 'n')
         # 5number of reads on disk
         # 6cumulative number of sectors read
         # 7number of writes on disk
         # 8cumulative number of sectors written
         # 9cancelled number of written sectors
         # 10TGID (group number of related tasks/threads) 
         # 11is_process (y/n).

      self.D_PRN=[]
         # 0PID
         # 1name (between brackets)
         # 2state
         # 3kernel module 'netatop' loaded ('y' or 'n')
         # 4number of TCP-packets  transmitted
         # 5cumulative size of TCP-packets transmitted
         # 6number of TCP-packets received
         # 7cumulative size of TCP-packets received
         # 8number of UDP-packets transmitted
         # 9cumulative size of UDP-packets transmitted
         # 10number of UDP-packets received
         # 11cumulative size of UDP-packets transmitted
         # 12number of raw packets transmitted (obsolete always 0)
         # 13number of raw packets received  (obsolete always  0)
         # 14TGID  (group  number  of related tasks/threads) 
         # 15is_process (y/n).
      self.D_offset=6
       # The  first part of each output-line consists of the following six fields:  
       #label (the name of the label), 
       #host (the name of  this machine)
       #epoch (the time of this interval as number of seconds since 1-1-1970), 
       #date (date of this interval  in format  YYYY/MM/DD)
       #time (time of this interval in format HH:MM:SS)
       #interval (number of seconds elapsed for this interval).
   def get(self,type):
      got=getstatusoutput('atop 1 1 -P'+type)
      if got[0] != 0:
         return None
      for line in got[1].split('\n'):
         if line == "RESET" or line=="SEP":
             continue
         eval("self.D_"+type+".append([])")
         for item in line.split(' '):
            eval("self.D_"+type+"[-1].append(item)")
      return (eval("self.D_"+type))
   def get_mem_percentage_cmd(self,cmd):
      re=self.get('PRM')
      rsize=0
      for item in re:
         cmd_now=item[self.D_offset+1].strip('\')(') 
         if cmd_now == cmd:
            print(cmd_now,cmd)
            print(item[self.D_offset+5])
            rsize=rsize+int(item[self.D_offset+5])
      re=self.get('MEM')      
      total=int(re[0][self.D_offset+0])*int(re[0][self.D_offset+1])/1024 # in Kbytes
      print(rsize)
      print(total)
      percent=rsize/total
      return percent
if __name__ == "__main__":
   ca=catcher()
   if len(sys.argv) > 1:
      #re=ca.get(sys.argv[1])
      print(ca.get_mem_percentage_cmd(sys.argv[1]))
   else:
      print("./catcher.py  CPU | cpu |CPL | MEM | SWP |PAG |LVM |MDD |DSK |NET |PRG |  PRC |PRM |PRD |PRN ")  
   
