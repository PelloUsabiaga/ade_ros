# ade\_ros
ADE Master ROS2
### Install Ubuntu server LTS 20.04.4

### Ensure that the Ubuntu Universe repository is enabled
sudo apt install software-properties-common

sudo add-apt-repository universe

### Add the ROS 2 GPG key with apt
sudo apt update && sudo apt install curl -y

sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

### Then add the repository to your sources list

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

### Install ROS 2 packages
sudo apt update
sudo apt upgrade

### ROS base install
sudo apt install ros-humble-ros-base

### ROS development tools
sudo apt install ros-dev-tools

### ROS2 workspace

There is a ROS2 workspace created, in which for the moment 3 packages will go. By now, there is only test\_package created. It has one node, which by now serves a example Flask app in the host, in port 5000. It is necesary to install flask to run it, install it with

pip3 install flask

and pip can be installed with

sudo apt install python3-pip

Also to write to serial it's necesary the wiringPi library which can be installed with

git clone https://github.com/WiringPi/WiringPi.git

cd WiringPi

./build debian

mv debian-template/wiringpi_3.4_arm64.deb .

sudo apt install ./wiringpi_3.4_arm64.deb

### ROS2 init service configuration

Inside service_files folder there are two files that are required to start our ROS 2 system on boot. Using ros.service file we create a service for systems, that service runs on boot and executes a bash script, which is the script that sources the needed files and launch the ros2 nodes. To configure the service run the following,

sudo touch /etc/systemd/system/ros.service 

and write inside the content we provide, then

sudo touch /usr/local/bin/exec-ros

and do the same,

to change the permissions run sudo chmod 744 /usr/local/bin/exec-ros

and finally to enable the service run

systemctl enable ros
