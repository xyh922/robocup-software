#pragma once

#include <vector>

#include <Geometry2d/Point.hpp>
#include <Configuration.hpp>

#include "KalmanBall.hpp"
#include "vision/robot/WorldRobot.hpp"

class BallBounce {
public:
    /**
     * Calculates whether the given kalman ball will bounce against another robot and
     * the resulting velocity vector
     *
     * @param ball Kalman ball we are trying to test
     * @param yellowRobots Best estimation of the yellow robots states
     * @param blueRobots Best esetimation of the yellow robots states
     * @param outNewVel Output of the resulting velocity vector after bounce
     *
     * @return Whether the ball bounces or not
     */
    static bool CalcBallBounce(KalmanBall& ball,
                               std::vector<WorldRobot>& yellowRobots,
                               std::vector<WorldRobot>& blueRobots,
                               Geometry2d::Point& outNewVel);

    static void createConfiguration(Configuration* cfg);

private:
    /**
     * Returns whether the ball is most likely intersecting the robots
     *
     * Note: Ignores the extra mouth calculations
     *
     * @param ball The ball we want to check for intersection with
     * @param robot The robot we what to check for intersection with
     */
    static bool BallInRobot(KalmanBall& ball, WorldRobot& robot);

    /**
     * Finds the 1 or 2 interserct locations on the ball shell
     *
     */
    static std::vector<Geometry2d::Point> PossibleBallIntersectionPts(
            KalmanBall& ball, WorldRobot& robot);
    )

    // Linear velocity dampen
    static ConfigDouble* robot_body_lin_dampen;
    static ConfigDouble* robot_mouth_lin_dampen;
    // Reflect Angle dampen
    static ConfigDouble* robot_body_angle_dampen;
    static ConfigDouble* robot_mouth_angle_dampen;