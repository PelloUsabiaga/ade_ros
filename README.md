# ade\_ros
## ADE Master ROS2

In the picture below it's shown the topology of our system, there are three nodes, each one dedicated to one simple task. The nodes share data between them using services and topics like \PositionMeasurement. The purpose of the system is the smooth control of a servo motor, controlling not only the position but also the speed. The Web node creates a Web server that send the user request using HTTP to the node, this data is processed and interpolated and finally sent trought a serial port to an Arduino board. The Arduino board is programmed to parse the data and control the motor using a PWM signal.

<img src="/ros_host/ROS.png" width="500">

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
