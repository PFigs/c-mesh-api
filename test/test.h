/* Wirepas Oy licensed under Apache License, Version 2.0
 *
 * See file LICENSE for full license details.
 *
 */

/**
 * \brief   Run all the tests
 */
int Test_runAll();

/**
 * \brief   Test scratchpad functionality
 */
int Test_scratchpad();

/**
 * \brief   Test CDD API related functionality
 */
int Test_configuration_data_distribution_api();

/**
 * \brief   Returns number of passed test cases
 */
int GetPassedTestCount();

/**
 * \brief   Returns number of failed test cases
 */
int GetFailedTestCount();
