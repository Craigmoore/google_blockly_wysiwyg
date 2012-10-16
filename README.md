google_blockly_wysiwyg
======================

Integration module to put google blockly into Drupal using the Wysiwyg API

There are three main files in this integration, and in the header of each file is where the file needs to go.

To summarise :

blockly.inc needs to go into the wysiwyg/editors folder.
blockly.css needs to go into the wysiwyg/editors/css folder.
blockly.js needs to go into the wysiwyg/editors/js folder.

To use this integration, install Drupal wysiwyg, download google blockly from 

http://blockly.googlecode.com/svn/trunk/

And name the folder "blockly" and put it into sites/all/libraries, so that the blockly code is at

libraries/blockly/blockly_compressed.js

Useage

Complete all the above tasks (downloading and enabling wysiwyg, downloading and moving the three blockly integration files into the correct folder and downloading and moving the google blockly project into libraries/blockly)
Go into Drupal and configure a new text format without any filters and set up a wysiwyg profile for this text format using blockly.

Create a content type with a field of type long text / long text with summary, and select the default editor to be blockly.

You will now be able to create blockly code and it will be saved in XML format in the content type, to be used perhaps by another module, meaning you could potentially capture "safe" javascript code as user generated content.


Limitations

As the blockly code itself does not do "instances" as ckeditor does, only one editor can be on the screen at once working correctly.