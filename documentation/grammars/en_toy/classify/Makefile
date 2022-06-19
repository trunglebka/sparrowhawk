tokenize_and_classify.far: tokenize_and_classify.grm cardinal.far date.far measure.far money.far punctuation.far time.far ../util.far word.far
	thraxcompiler --input_grammar=$< --output_far=$@

cardinal.far: cardinal.grm ../byte.far ../util.far
	thraxcompiler --input_grammar=$< --output_far=$@

../byte.far: ../byte.grm 
	thraxcompiler --input_grammar=$< --output_far=$@

../util.far: ../util.grm ../byte.far
	thraxcompiler --input_grammar=$< --output_far=$@

date.far: date.grm ../byte.far ../util.far months.tsv months2.tsv
	thraxcompiler --input_grammar=$< --output_far=$@

measure.far: measure.grm ../byte.far ../util.far measure.tsv
	thraxcompiler --input_grammar=$< --output_far=$@

money.far: money.grm ../byte.far ../util.far money.tsv
	thraxcompiler --input_grammar=$< --output_far=$@

punctuation.far: punctuation.grm ../util.far
	thraxcompiler --input_grammar=$< --output_far=$@

time.far: time.grm ../byte.far ../util.far
	thraxcompiler --input_grammar=$< --output_far=$@

word.far: word.grm ../byte.far ../util.far ../../sentence_boundary_exceptions.txt
	thraxcompiler --input_grammar=$< --output_far=$@

clean:
	rm -f cardinal.far date.far measure.far money.far punctuation.far time.far ../util.far word.far ../byte.far
