# ade\_ros
## ADE Master ROS2

This project intends to test ROS 2 as a software developing tool, whitch was unknown for us before. For that, a simple project in whitch a servomotor is controlled from a web interface have been propoused and developed.

In the picture below it's shown the topology of our system, with the ROS programs in the Raspberry Pi host, and the Arduino microcontroller managing the servomotor. There are three ROS nodes, each one dedicated to one simple task: the flask web server node, the trajectory interpolation node, and the serial controller node. The nodes share data between them using ROS services and topics, like for example a service to request a trajectory generation an get the trajectory as a response, or a topic in whitch the possition of the motor is published. 

<img src="/ros_host/ROS.png" width="500">

The web server is written in Flask, a simple python library to write web applications. It offers a single page, with the operator panel of the motor, and

The detailed ROS documentation needed to recreate this project is available [HERE](https://docs.ros.org/en/humble/index.html)

### Install Ubuntu server LTS 20.04.4

You can do it easily using the RPI imager.

### Ensure that the Ubuntu Universe repository is enabled

>sudo apt install software-properties-common

>sudo add-apt-repository universe

### Add the ROS 2 GPG key with apt
>sudo apt update && sudo apt install curl -y

>sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

### Then add the repository to your sources list

>echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

### Install ROS 2 packages

>sudo apt update

>sudo apt upgrade

### ROS base install
>sudo apt install ros-humble-ros-base

### ROS development tools
>sudo apt install ros-dev-tools

### ROS2 workspace

There is a ROS2 workspace created, in which they are 4 packets. Each packet has one node, except for the packet which has the interfaces. It is necesary to install some libraries to run the packets properly: flask, matplotlib and WiringPi, install them with,

- Install pip if needed
  
  >sudo apt install python3-pip
  
- Flask

  >pip3 install flask

- WiringPi

  >git clone https://github.com/WiringPi/WiringPi.git

  >cd WiringPi

  >./build debian

  >mv debian-template/wiringpi_3.4_arm64.deb .

  >sudo apt install ./wiringpi_3.4_arm64.deb
  
>[!IMPORTANT]
>If you have errors with the last commands, probably the version of the library has changed, so you have to look inside debian-template directory to find the correct one. 

- Matplotlib

  >pip3 install matplotlib

### ROS2 init service configuration

Inside service_files folder there are two files that are required to start our ROS 2 system on boot. Using ros.service file we create a service for systems, that service runs on boot and executes a bash script, which is the script that sources the needed files and launch the ros2 nodes.

To configure the service run the following,

>sudo touch /etc/systemd/system/ros.service 

and write inside the content we provide, then run

>sudo touch /usr/local/bin/exec-ros

and do the same,

to change the permissions run

>sudo chmod 744 /usr/local/bin/exec-ros

and finally to enable the service run

>systemctl enable ros

>[!Note]
> If you have problems cause not found modules try to install the problematic modules using sudo.
