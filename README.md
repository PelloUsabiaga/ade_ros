# ade\_ros
ADE Master ROS2
## Install Ubuntu server LTS 20.04.4

## Ensure that the Ubuntu Universe repository is enabled
sudo apt install software-properties-common
sudo add-apt-repository universe

## Add the ROS 2 GPG key with apt
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

## Then add the repository to your sources list

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

## Install ROS 2 packages
sudo apt update
sudo apt upgrade

## ROS base install
sudo apt install ros-humble-ros-base

## ROS development tools
sudo apt install ros-dev-tools
### ROS2 workspace

There is a ROS2 workspace created, in which for the moment 3 packages will go. By now, there is only test\_package created. It has one node, which by now serves a example Flask app in the host, in port 5000. It is necesary to install flask to run it, install it with

pip3 install flask

and pip can be installed with

sudo apt install python3-pip
