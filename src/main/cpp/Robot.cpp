/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/DoubleSolenoid.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/TimedRobot.h>
//  #include <CameraServer.h>
//#include <frc/DifferentialDrive.h>
//#include <SpeedControllerGroup.h>
//#include <IterativeRobot.h>
//include <frc/Joystick.h>
#include "ctre/Phoenix.h"
#include <frc/robotdrive.h>
#include <frc/Spark.h>
#include <frc/DigitalInput.h>
#include "frc/WPILIb.h"
#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

/**
 * This is a sample program showing the use of the solenoid classes during
 * operator control.
 *
 * Three buttons from a joystick will be used to control two solenoids: One
 * button to control the position of a single solenoid and the other two buttons
 * to control a double solenoid.
 *
 * Single solenoids can either be on or off, such that the air diverted through
 * them goes through either one channel or the other.
 *
 * Double solenoids have three states: Off, Forward, and Reverse. Forward and
 * Reverse divert the air through the two channels and correspond to the on and
 * off of a single solenoid, but a double solenoid can also be "off", where both
 * channels are diverted to exhaust such that there is no pressure in either
 * channel.
 *
 * Additionally, double solenoids take up two channels on your PCM whereas
 * single solenoids only take a single channel.
 */
class Robot : public frc::TimedRobot {
 
 
	WPI_TalonSRX m_FLMotor{21};
	WPI_TalonSRX m_FRMotor{23};
	WPI_TalonSRX m_BLMotor{22};
	WPI_TalonSRX m_BRMotor{24};
  //WPI_VictorSPX m_ElvLeft{25};
  //WPI_VictorSPX m_ElvRight{26};
	frc::SpeedControllerGroup m_right{m_FRMotor, m_BRMotor};
	frc::SpeedControllerGroup m_left{m_FLMotor, m_BLMotor};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};
	int autoLoopCounter;
  bool autoEnable;
  frc::Timer m_timer;
 
 public:
  void RobotInit() {
//		frc::CameraServer::GetInstance()->StartAutomaticCapture();
//		frc::CameraServer::GetInstance()->StartAutomaticCapture();
 //   	bool LLMode = false;
	}

  void AutonomousInit() {
 /* m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }  */

  frc::Timer m_timer;
  m_timer.Reset();
}

  void AutonomousPeriodic() override{
    //m_robotDrive.ArcadeDrive(.5,0);
    if (m_timer.Get() < .5 ) {
     m_robotDrive.ArcadeDrive(.5,0);
    }
    else if (m_timer.Get() < 1){
     m_robotDrive.ArcadeDrive(.5,.5);
    }
    else
    {
       m_robotDrive.ArcadeDrive(0,0);
      /* code */
    }
    

  /* The output of GetRawButton is true/false depending on whether the button
     * is pressed; Set takes a boolean for for whether to use the default
     * (false) channel or the other (true).
     */
    //  m_solenoid.Set(m_stick.GetRawButton(kSolenoidButton));

    /* In order to set the double solenoid, we will say that if neither button
     * is pressed, it is off, if just one button is pressed, set the solenoid to
     * correspond to that button, and if both are pressed, set the solenoid to
     * Forwards.
     */
  /* std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
		double targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0) - 8;

		double l_ta = table->GetNumber("ta",0.0);
		if(m_stick1.GetRawButton(1) && l_ta <= 10){
			if (targetOffsetAngle_Horizontal > 2){
				m_robotDrive.ArcadeDrive(-m_stick1.GetY(),.45);
			}else if (targetOffsetAngle_Horizontal < -2){
 				m_robotDrive.ArcadeDrive(-m_stick1.GetY(),-.45);
			}else{
				m_robotDrive.ArcadeDrive(-m_stick1.GetY(), 0);
			}
		}else {
			 m_robotDrive.ArcadeDrive(m_stick1.GetY()*-1, m_stick2.GetX());
			 m_ElvRight.Set(m_stick.GetY());
			 m_ElvLeft.Set(m_stick.GetY()*(-1));
 
		 	if (m_stick.GetRawButton(5)) {
  				m_SparkL.Set(-.6);
 				m_SparkR.Set(-.6);
			 } else if (m_stick.GetRawButton(6)) {
		  		m_SparkL.Set(.6);
         		m_SparkR.Set(.6);
	 		 } else {
			    m_SparkL.Set(0);
			    m_SparkR.Set(0);
		  
	 		 }
    }



    if (m_stick.GetRawButton(1)) {
      m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
    } else if (m_stick.GetRawButton(2)) {
      m_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
    } else {
      m_doubleSolenoid.Set(frc::DoubleSolenoid::kOff);
    }
    if (m_stick.GetRawButton(3)) {
      m_doubleSolenoid1.Set(frc::DoubleSolenoid::kForward);
    } else if (m_stick.GetRawButton(4)) {
      m_doubleSolenoid1.Set(frc::DoubleSolenoid::kReverse);
    } else {
      m_doubleSolenoid1.Set(frc::DoubleSolenoid::kOff);
    }

*/
  }

  void TeleopPeriodic() override {


	
  // frc::wait(.5);
  // m_robotDrive.ArcadeDrive(-.2,0);


    /* The output of GetRawButton is true/false depending on whether the button
     * is pressed; Set takes a boolean for for whether to use the default
     * (false) channel or the other (true).
     */
    //  m_solenoid.Set(m_stick.GetRawButton(kSolenoidButton));

    /* In order to set the double solenoid, we will say that if neither button
     * is pressed, it is off, if just one button is pressed, set the solenoid to
     * correspond to that button, and if both are pressed, set the solenoid to
     * Forwards.
     */
   /* std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
		double targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0) - 8;

		double l_ta = table->GetNumber("ta",0.0);
		if(m_stick1.GetRawButton(1) && l_ta <= 10){
			if (targetOffsetAngle_Horizontal > 2){
				m_robotDrive.ArcadeDrive(-m_stick1.GetY(),.45);
			}else if (targetOffsetAngle_Horizontal < -2){
 				m_robotDrive.ArcadeDrive(-m_stick1.GetY(),-.45);
			}else{
				m_robotDrive.ArcadeDrive(-m_stick1.GetY(), 0);
			}
		}else {
			 m_robotDrive.ArcadeDrive(m_stick1.GetY()*-1, m_stick2.GetX());
			 m_ElvRight.Set(m_stick.GetY());
			 m_ElvLeft.Set(m_stick.GetY()*(-1));
 
		 	if (m_stick.GetRawButton(5)) {
  				m_SparkL.Set(-.6);
 				m_SparkR.Set(-.6);
			 } else if (m_stick.GetRawButton(6)) {
		  		m_SparkL.Set(.6);
         		m_SparkR.Set(.6);
	 		 } else {
			    m_SparkL.Set(0);
			    m_SparkR.Set(0);
		  
	 		 }
    }



    if (m_stick.GetRawButton(1)) {
      m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
    } else if (m_stick.GetRawButton(2)) {
      m_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
    } else {
      m_doubleSolenoid.Set(frc::DoubleSolenoid::kOff);
    }
    if (m_stick.GetRawButton(3)) {
      m_doubleSolenoid1.Set(frc::DoubleSolenoid::kForward);
    } else if (m_stick.GetRawButton(4)) {
      m_doubleSolenoid1.Set(frc::DoubleSolenoid::kReverse);
    } else {
      m_doubleSolenoid1.Set(frc::DoubleSolenoid::kOff);
      */
   // }
   	m_robotDrive.ArcadeDrive(m_stick1.GetY(),m_stick1.GetX());
  }

 private:
  frc::Joystick m_stick{0};
      frc::DigitalInput m_Switch{0};
  frc::Joystick m_stick1{1};
frc::Joystick m_stick2{2};
frc::Spark m_SparkL{0};
 frc::Spark m_SparkR{2};
  // Solenoid corresponds to a single solenoid.
  // frc::Solenoid m_solenoid{0};

  // DoubleSolenoid corresponds to a double solenoid.
  frc::DoubleSolenoid m_doubleSolenoid{0,1};
  frc::DoubleSolenoid m_doubleSolenoid1{2,3};

  static constexpr int kSolenoidButton = 1;
  static constexpr int kDoubleSolenoidForward = 2;
  static constexpr int kDoubleSolenoidReverse = 3;
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
