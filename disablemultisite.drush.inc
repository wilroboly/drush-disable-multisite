<?php

/**
 * @file
 * Disable Multisite drush command.
 *
 * To run this command, execute `sudo drush --include=./disable-multisite true -y`
 * from within your drush directory.
 *
 * See `drush topic docs-commands` for more information about command authoring.
 *
 * You can copy this file to any of the following
 *   1. A .drush folder in your HOME folder.
 *   2. Anywhere in a folder tree below an active module on your site.
 *   3. /usr/share/drush/commands (configurable)
 *   4. In an arbitrary folder specified with the --include option.
 *   5. Drupal's /drush or /sites/all/drush folders, or in the /drush
 *        folder in the directory above the Drupal root.
 */

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 */
function disablemultisite_drush_command() {
  $items = array();

  // The 'disable-multisite' command.
  $items['disable-multisite'] = array(
    'description' => "Disable Multisite functionality in Drupal.",
    'arguments' => array(
      'toggle' => 'Boolean value toggle where TRUE disables the multisite and FALSE enables the multisite. Defaults to true.',
    ),
    'examples' => array(
      'drush disable-multisite true' => 'Disables Multisite functionality',
    ),
    'aliases' => array('disable-ms', 'dms'),
    // No bootstrap at all.
    'bootstrap' => DRUSH_BOOTSTRAP_NONE,
  );

  // The 'disable-multisite-status' command.  Prints current state of the toggle.
  $items['disable-multisite-status'] = array(
    'description' => "Display the current state of the multisite toggle.",
    'examples' => array(
      'drush disable-multisite-status' => 'Prints current state of the toggle',
    ),
    'aliases' => array('disable-mss','dmss'),
    
    // Example output engine data:  command returns a deep array
    // that can either be printed in table format or as a json array.
    'engines' => array(
      'outputformat' => array(
        'default' => 'table',
        'pipe-format' => 'json',
        // Commands that return deep arrays will usually use
        // machine-ids for the column data.  A 'field-labels'
        // item maps from the machine-id to a human-readable label.
        'field-labels' => array(
          'name' => 'Name',
          'description' => 'Description',
          'available' => 'Num',
          'taste' => 'Taste',
        ),
        // In table format, the 'column-widths' item is consulted
        // to determine the default weights for any named column.
        'column-widths' => array(
          'name' => 10,
          'available' => 3,
        ),
        'require-engine-capability' => array('format-table'),
      ),
    ),
    // No bootstrap at all.
    'bootstrap' => DRUSH_BOOTSTRAP_NONE,
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'. This hook is optional. If a command
 * does not implement this hook, the command's description is used instead.
 *
 * This hook is also used to look up help metadata, such as help
 * category title and summary.  See the comments below for a description.
 */
function disablemultisite_drush_help($section) {
  switch ($section) {
    case 'drush:disable-multisite':
      return dt("This command will toggle the state of the disable multisite function.");

  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 *
 * The validate command should exit with
 * `return drush_set_error(...)` to stop execution of
 * the command.  In practice, calling drush_set_error
 * OR returning FALSE is sufficient.  See drush.api.php
 * for more details.
 */
function drush_disablemultisite_disable_multisite_validate() {
  if (drush_is_windows()) {
    // $name = drush_get_username();
    // @todo Implement check for elevated process using w32api
    // as sudo is not available for Windows
    // @see http://php.net/manual/en/book.w32api.php
    // @see http://social.msdn.microsoft.com/Forums/en/clr/thread/0957c58c-b30b-4972-a319-015df11b427d
  }
  else {
    $name = posix_getpwuid(posix_geteuid());
    if ($name['name'] !== 'root') {
      return drush_set_error('USER_ERROR', dt('What? Something is wrong in Denmark.'));
    }
  }
}

/**
 * Implements drush_hook_COMMAND().
 *
 * The command callback is where the action takes place.
 *
 * The function name should be same as command name but with dashes turned to
 * underscores and 'drush_commandfile_' prepended, where 'commandfile' is
 * taken from the file 'commandfile.drush.inc', which in this case is
 * 'sandwich'. Note also that a simplification step is also done in instances
 * where the commandfile name is the same as the beginning of the command name,
 * "drush_example_example_foo" is simplified to just "drush_example_foo".
 * To also implement a hook that is called before your command, implement
 * "drush_hook_pre_example_foo".  For a list of all available hooks for a
 * given command, run drush in --debug mode.
 *
 * If for some reason you do not want your hook function to be named
 * after your command, you may define a 'callback' item in your command
 * object that specifies the exact name of the function that should be
 * called.
 *
 * In this function, all of Drupal's API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_disablemultisite_disable_multisite($toggle = 'true') {
  /*
  $msg = dt('Okay. Enjoy this !filling sandwich!str_spreads.',
            array('!filling' => $filling, '!str_spreads' => $str_spreads)
         );
  drush_print("\n" . $msg . "\n");

  if (drush_get_context('DRUSH_NOCOLOR')) {
    $filename = dirname(__FILE__) . '/sandwich-nocolor.txt';
  }
  else {
    $filename = dirname(__FILE__) . '/sandwich.txt';
  }
  drush_print(file_get_contents($filename));
  // Find out how many sandwiches have been served, and set
  // the cached value to one greater.
  $served = drush_sandwich_sandwiches_served();
  drush_cache_set(drush_get_cid('sandwiches-served'), $served + 1);
  */
}

/**
 * Implements drush_hook_COMMAND().
 *
 * This ficticious command shows how a deep array can be constructed
 * and used as a command return value that can be output by different
 * output formatters.
 */
function drush_disablemultisite_disable_multisite_status() {
  return array(
    'ketchup' => array(
      'name' => 'Ketchup',
      'description' => 'Some say its a vegetable, but we know its a sweet spread.',
      'available' => '7',
      'taste' => 'sweet',
    ),
    'mayonnaise' => array(
      'name' => 'Mayonnaise',
      'description' => 'A nice dairy-free spead.',
      'available' => '12',
      'taste' => 'creamy',
    ),
    'mustard' => array(
      'name' => 'Mustard',
      'description' => 'Pardon me, but could you please pass that plastic yellow bottle?',
      'available' => '8',
      'taste' => 'tangy',
    ),
    'pickles' => array(
      'name' => 'Pickles',
      'description' => 'A necessary part of any sandwich that does not taste terrible.',
      'available' => '63',
      'taste' => 'tasty',
    ),
  );
}

/**
 * Command argument complete callback.
 *
 * Provides argument values for shell completion.
 *
 * @return array
 *   Array of popular fillings.
 */
function sandwich_make_me_a_sandwich_complete() {
  return array('values' => array('turkey', 'cheese', 'jelly', 'butter'));
}