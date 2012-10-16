<?php

/* This needs to be copied into wysiwyg/editors folder */

/**
 * Plugin implementation of hook_editor().
 */
function wysiwyg_blockly_editor() {
	$editor['blockly'] = array(
		'title' => 'blockly',
	  'vendor url' => 'http://code.google.com/p/blockly/',
    'download url' => 'http://blockly.googlecode.com/svn/trunk/',
		'libraries' => array(
			'' => array(
				'title' => 'Default',
				'files' => array(
					'blockly_compressed.js' => array('preprocess' => FALSE),
					'generators/javascript.js' => array('preprocess' => FALSE),
					'generators/javascript/control.js' => array('preprocess' => FALSE),
					'generators/javascript/logic.js' => array('preprocess' => FALSE),
					'generators/javascript/math.js' => array('preprocess' => FALSE),
					'generators/javascript/text.js' => array('preprocess' => FALSE),
					'generators/javascript/lists.js' => array('preprocess' => FALSE),
					'generators/javascript/variables.js' => array('preprocess' => FALSE),
					'generators/javascript/procedures.js' => array('preprocess' => FALSE),
					'language/en/_messages.js' => array('preprocess' => FALSE),
					'language/common/control.js' => array('preprocess' => FALSE),
					'language/common/logic.js' => array('preprocess' => FALSE),
					'language/common/math.js' => array('preprocess' => FALSE),
					'language/common/text.js' => array('preprocess' => FALSE),
					'language/common/lists.js' => array('preprocess' => FALSE),
					'language/common/variables.js' => array('preprocess' => FALSE),
					'language/common/procedures.js' => array('preprocess' => FALSE),
				),
     	),
		),
    'version callback' => 'wysiwyg_blockly_version',
		'versions' => array(
      'latest' => array(
        'js files' => array('blockly.js'),
				'css files' => array('blockly.css', '../../../../../libraries/blockly/blockly.css'),
	    ),
    ),
    'install note callback' => 'wysiwyg_blockly_install_note',
    'themes callback' => 'wysiwyg_blockly_themes',
    
    /*
    'settings form callback' => 'wysiwyg_blockly_settings_form',
    'init callback' => 'wysiwyg_blockly_init',
    'settings callback' => 'wysiwyg_blockly_settings',
    'plugin callback' => 'wysiwyg_blockly_plugins',
    'plugin settings callback' => 'wysiwyg_blockly_plugin_settings',
    'proxy plugin' => array(
      'drupal' => array(
        'load' => TRUE,
        'proxy' => TRUE,
      ),
    ),
    'proxy plugin settings callback' => 'wysiwyg_ckeditor_proxy_plugin_settings',
*/
	);
	return $editor;
}

function wysiwyg_blockly_install_note() {
  return '<p class="warning">' . t('This editor is in alpha! Apologies for parts not working, email craigmoore@flashygraphics.co.uk.') . '</p>';
}

// This function *detects* which version of the library you have installed by loading a file
// But we just return latest
function wysiwyg_blockly_version() {
	return 'latest';
}
function wysiwyg_blockly_themes() {
	return array('default');
}
function wysiwyg_blockly_settings_form() {}
function wysiwyg_blockly_init() {}
function wysiwyg_blockly_settings() {}
function wysiwyg_blockly_plugins() {}
function wysiwyg_blockly_plugin_settings() {}