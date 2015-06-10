Drush Disable Mulsite Plug-in
=============================

This is a plugin for drush which provides a disable/enable toggle for multisite 
functionality in Drupal 7. This plugin is mainly used for flushing out a 
cascading directory search for the settings.php file for Drupal.

After some extensive performance evaluation, it has been noted that searching
through a series of potential directories for the default settings.php file 
or a specific settings.php file can carve some time off each page rendering.

If your Drupal installation does not have use or will likely not employ any of 
the Drupal multisite requirements, it is advantageous to simply turn this 
feature off. This does require replacing the bootstrap.inc and index.php file
with modified versions.

## Process

This plug-in attempts to figure out which version of Drupal you have installed,
after which, according to the webserver you are running, the proper modification
will be made to the necessary files. A backup is kept incase of a need to revert
the changes (enable multisite). 

## Options

{TBD}

## Creators

* William Roboly
* Jamon Camisso