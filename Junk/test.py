from haystack.nodes import PromptNode

prompt_node = PromptNode(model_name_or_path="google/flan-t5-large")

temp = prompt_node.get_prompt_template_names()
print(temp)