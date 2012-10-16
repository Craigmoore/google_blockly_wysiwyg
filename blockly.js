/* This needs to be copied into wysiwyg/editors/js folder */

(function($) {
	
	var getCurrentDomain = function() {
		var currentLocation = document.location.href;
		var pieces = currentLocation.split('/');
		pieces = pieces.splice(0, 3);
		return pieces.join('/');
	};
	
	Blockly.instances = Blockly.instances || {};
	
	Drupal.wysiwyg.editor.init.blockly = function(settings) {};
	Drupal.wysiwyg.editor.attach.blockly = function(context, params, settings) {
	
		var $tempfield = $('#' + params.field);
		
		var instance = {
				$container : $tempfield.parent(),
				dimensions : {width : $tempfield.parent().width(), height : $tempfield.parent().height()},
				originalValue : $tempfield.val(),
				$toolbar : $('<div />'),
				$workspace : $('<div />'),
				$field : $tempfield
		};
		$tempfield.hide();
		$tempfield.after(instance.$toolbar);
		var runButton = $('<a href="#">Run</a>');
		runButton.css({
			float : 'right'
		});
		runButton.bind('click', function(e) {
			e.stopPropagation();
			var code = Blockly.Generator.workspaceToCode('JavaScript');
			console.log(code);
			try {
				eval(code);
				init([['Hello', 'World'], ['Hello', 'World']]);
			} catch (e) {
				alert('Program error:\n' + e);
			}
			return false;
		});
		instance.$toolbar.append(runButton);
		instance.$toolbar.after(instance.$workspace);
		instance.$workspace.addClass('blocklyContainer');
		instance.$workspace.width(instance.dimensions.width);
		instance.$workspace.height(instance.dimensions.height);
		Blockly.instances[params.field] = instance;
		
	    Blockly.inject(instance.$workspace[0], { path : getCurrentDomain() + '/sites/all/libraries/blockly/'});
	    try {
	    	var xml = Blockly.Xml.textToDom(instance.originalValue);
	    	Blockly.Xml.domToWorkspace(Blockly.mainWorkspace, xml);
	    }
	    catch (e) {
	    }
	    Blockly.mainWorkspace.render();
	};
	Drupal.wysiwyg.editor.detach.blockly = function(context, params, trigger) {
		var instance = Blockly.instances[params.field];
		instance.$field.show();
		instance.$field.val(Blockly.Xml.domToText(Blockly.Xml.workspaceToDom(Blockly.mainWorkspace)));
		instance.$workspace.detach();
		delete Blockly.instances[params.field];
	};
	Drupal.wysiwyg.editor.instance.blockly = {
		addPlugin : function(pluginName, settings, pluginSettings) {
		},
		prepareContent : function(content) {
			return content;
		},
		insert : function(content) {
		},
		setContent : function(content) {
		},
		getContent : function() {
		}
	};

})(jQuery);