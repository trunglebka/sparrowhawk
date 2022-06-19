verbalize.far: verbalize.grm date.far measure.far money.far numbers.far time.far verbatim.far
	thraxcompiler --input_grammar=$< --output_far=$@

date.far: date.grm ../byte.far ../util.far numbers.far
	thraxcompiler --input_grammar=$< --output_far=$@

../byte.far: ../byte.grm 
	thraxcompiler --input_grammar=$< --output_far=$@

../util.far: ../util.grm ../byte.far
	thraxcompiler --input_grammar=$< --output_far=$@

numbers.far: numbers.grm ../byte.far ../util.far CARDINAL_NUMBER_NAME ORDINAL_NUMBER_NAME
	thraxcompiler --input_grammar=$< --output_far=$@

measure.far: measure.grm ../byte.far ../util.far numbers.far
	thraxcompiler --input_grammar=$< --output_far=$@

money.far: money.grm ../byte.far ../util.far numbers.far money.tsv
	thraxcompiler --input_grammar=$< --output_far=$@

time.far: time.grm ../byte.far ../util.far numbers.far
	thraxcompiler --input_grammar=$< --output_far=$@

verbatim.far: verbatim.grm ../byte.far ../util.far
	thraxcompiler --input_grammar=$< --output_far=$@

clean:
	rm -f date.far measure.far money.far numbers.far time.far verbatim.far ../byte.far ../util.far
